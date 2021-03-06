////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 by EMC Corporation, All Rights Reserved
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is EMC Corporation
///
/// @author Andrey Abramov
/// @author Vasiliy Nabatchikov
////////////////////////////////////////////////////////////////////////////////

#include "shared.hpp"
#include "segment_writer.hpp"
#include "store/store_utils.hpp"
#include "index_meta.hpp"
#include "analysis/token_stream.hpp"
#include "analysis/token_attributes.hpp"
#include "utils/log.hpp"
#include "utils/map_utils.hpp"
#include "utils/timer_utils.hpp"
#include "utils/type_limits.hpp"
#include "utils/version_utils.hpp"

#include <math.h>
#include <set>

NS_ROOT

segment_writer::column::column(
    const string_ref& name, 
    columnstore_writer& columnstore) {
  this->name.assign(name.c_str(), name.size());
  this->handle = columnstore.push_column();
}

doc_id_t segment_writer::begin(
    const update_context& ctx,
    size_t reserve_rollback_extra /*= 0*/
) {
  assert(docs_cached() + type_limits<type_t::doc_id_t>::min() - 1 < type_limits<type_t::doc_id_t>::eof());
  valid_ = true;
  norm_fields_.clear(); // clear norm fields
  docs_mask_.reserve(
    docs_mask_.size() + 1 + reserve_rollback_extra
  ); // reserve space for potential rollback
  docs_context_.emplace_back(ctx);

  return docs_cached() + type_limits<type_t::doc_id_t>::min() - 1; // -1 for 0-based offset
}

segment_writer::ptr segment_writer::make(directory& dir) {
  // can't use make_unique becuase of the private constructor
  return memory::maker<segment_writer>::make(dir);
}

size_t segment_writer::memory() const NOEXCEPT {
  return sizeof(segment_writer)
    + (sizeof(update_contexts::value_type) * docs_context_.size())
    + (sizeof(document_mask::value_type) * docs_mask_.size())
    + fields_.memory()
    ;
}

bool segment_writer::remove(doc_id_t doc_id) {
  return type_limits<type_t::doc_id_t>::valid(doc_id)
    && (doc_id - type_limits<type_t::doc_id_t>::min()) < docs_cached()
    && docs_mask_.insert(doc_id).second;
}

segment_writer::segment_writer(directory& dir) NOEXCEPT
  : dir_(dir), initialized_(false) {
}

bool segment_writer::index(
    const hashed_string_ref& name,
    token_stream& tokens,
    const flags& features) {
  REGISTER_TIMER_DETAILED();

  assert(docs_cached() + type_limits<type_t::doc_id_t>::min() - 1 < type_limits<type_t::doc_id_t>::eof()); // user should check return of begin() != eof()
  auto doc_id =
    doc_id_t(docs_cached() + type_limits<type_t::doc_id_t>::min() - 1); // -1 for 0-based offset
  auto& slot = fields_.get(name);
  auto& slot_features = slot.meta().features;

  // invert only if new field features are a subset of slot features
  if ((slot.empty() || features.is_subset_of(slot_features)) &&
      slot.invert(tokens, slot.empty() ? features : slot_features, doc_id)) {
    if (features.check<norm>()) {
      norm_fields_.insert(&slot);
    }

    fields_ += features; // accumulate segment features
    return true;
  }

  return false;
}

columnstore_writer::column_output& segment_writer::stream(
    doc_id_t doc_id, const hashed_string_ref& name) {
  REGISTER_TIMER_DETAILED();

  static auto generator = [](
      const hashed_string_ref& key,
      const column& value) NOEXCEPT {
    // reuse hash but point ref at value
    return hashed_string_ref(key.hash(), value.name);
  };

  // replace original reference to 'name' provided by the caller
  // with a reference to the cached copy in 'value'
  return map_utils::try_emplace_update_key(
    columns_,                                     // container
    generator,                                    // key generator
    name,                                         // key
    name, *col_writer_                            // value
  ).first->second.handle.second(doc_id);
}

void segment_writer::finish() {
  REGISTER_TIMER_DETAILED();

  // write document normalization factors (for each field marked for normalization))
  float_t value;
  for (auto* field : norm_fields_) {
    value = 1.f / float_t(std::sqrt(double_t(field->size())));
    if (value != norm::DEFAULT()) {
      auto& stream = field->norms(*col_writer_);
      write_zvfloat(stream, value);
    }
  }
}

bool segment_writer::flush(std::string& filename, segment_meta& meta) {
  REGISTER_TIMER_DETAILED();

  // flush columnstore and columns indices
  if (col_writer_->flush() && !columns_.empty()) {
    struct less_t {
      bool operator()(
          const column* lhs,
          const column* rhs
      ) const NOEXCEPT {
        return lhs->name < rhs->name;
      };
    };

    std::set<const column*, less_t> columns;

    // ensure columns are sorted
    for (auto& entry : columns_) {
      columns.emplace(&entry.second);
    }

    // flush columns meta
    col_meta_writer_->prepare(dir_, meta);

    for (auto& column: columns) {
      col_meta_writer_->write(column->name, column->handle.first);
    }

    col_meta_writer_->flush();
    columns_.clear();
    meta.column_store = true;
  }

  // flush fields metadata & inverted data
  if (docs_cached()) {
    flush_state state;
    state.dir = &dir_;
    state.doc_count = docs_cached();
    state.name = seg_name_;
    state.ver = IRESEARCH_VERSION;

    fields_.flush(*field_writer_, state);
  }

  // write non-empty document mask
  if (!docs_mask_.empty()) {
    auto writer = meta.codec->get_document_mask_writer();

    writer->write(dir_, meta, docs_mask_);
  }

  assert(docs_cached() >= docs_mask_.size());
  meta.docs_count = docs_cached();
  meta.live_docs_count = meta.docs_count - docs_mask_.size();
  meta.files.clear(); // prepare empy set to be swaped into dir_

  if (!dir_.swap_tracked(meta.files)) {
    IR_FRMT_ERROR("Failed to swap list of tracked files in: %s", __FUNCTION__);

    return false;
  }

  // flush segment metadata
  {
    segment_meta_writer::ptr writer = meta.codec->get_segment_meta_writer();
    writer->write(dir_, meta);

    filename = writer->filename(meta);
  }

  return true;
}

void segment_writer::reset() {
  initialized_ = false;

  tracking_directory::file_set empty;

  if (!dir_.swap_tracked(empty)) {
    // on failre next segment might have extra files which will fail to get refs
    IR_FRMT_ERROR("Failed to swap list of tracked files in: %s", __FUNCTION__);
  }

  docs_context_.clear();
  docs_mask_.clear();
  fields_.reset();
}

void segment_writer::reset(const segment_meta& meta) {
  reset();

  seg_name_ = meta.name;

  if (!field_writer_) {
    field_writer_ = meta.codec->get_field_writer(false);
  }

  if (!col_meta_writer_) {
    col_meta_writer_ = meta.codec->get_column_meta_writer();
  }

  if (!col_writer_) {
    col_writer_ = meta.codec->get_columnstore_writer();
  }

  col_writer_->prepare(dir_, meta);
  initialized_ = true;
}

NS_END