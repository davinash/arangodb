#ifndef SQLPARSER_SQLPARSER_H
#define SQLPARSER_SQLPARSER_H

#include "SQLParserResult.h"
#include "sql/statements.h"
#include "../Aql/Query.h"

namespace hsql {

  // Static methods used to parse SQL strings.
  class SQLParser {
   public:

   /// @brief return the query during parsing
   inline arangodb::aql::Query* query() { return _query; }

      /// @brief return the ast during parsing
      inline arangodb::aql::Ast* ast() { return _ast; }

   /// @brief create the parser
   explicit SQLParser(arangodb::aql::Query*);

    // Parses a given constant character SQL string into the result object.
    // Returns true if the lexer and parser could run without internal errors.
    // This does NOT mean that the SQL string was valid SQL. To check that
    // you need to check result->isValid();
    bool parse(bool withDetails);

    // Run tokenization on the given string and store the tokens in the output vector.
    static bool tokenize(const std::string& sql, std::vector<int16_t>* tokens);

//    // Deprecated.
//    // Old method to parse SQL strings. Replaced by parse().
//    static bool parseSQLString(const char* sql, arangodb::aql::Parser* result);
//
//    // Deprecated.
//    // Old method to parse SQL strings. Replaced by parse().
//    static bool parseSQLString(const std::string& sql, arangodb::aql::Parser* result);

      /// @brief push a temporary value on the parser's stack
      void pushStack(void*);
      /// @brief pop a temporary value from the parser's stack
      void* popStack();
      /// @brief push an AstNode into the object element on top of the stack
      void pushObjectElement(char const*, size_t, arangodb::aql::AstNode*);

      /// @brief push an AstNode into the object element on top of the stack
      void pushObjectElement(arangodb::aql::AstNode*, arangodb::aql::AstNode*);

/// @brief peek at a temporary value from the parser's stack
      void* peekStack();
  private:
      /// @brief the query
      arangodb::aql::Query* _query;

      /// @brief abstract syntax tree for the query, build during parsing
      arangodb::aql::Ast* _ast;
      /// @brief a stack of things, used temporarily during parsing
      std::vector<void*> _stack;
  };
} // namespace hsql


#endif