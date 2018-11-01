
#include "SQLParser.h"
#include "parser/bison_parser.h"
#include "parser/flex_lexer.h"
#include <stdio.h>
#include <string>
#include <iostream>

#include "../Aql/Scopes.h"

namespace hsql {

    SQLParser::SQLParser(arangodb::aql::Query* query)
      : _query(query),
        _ast(query->ast()),
        _stack() {

        _stack.reserve(4);
    }
  // static
  bool SQLParser::parse(bool withDetails) {
    yyscan_t scanner;
    YY_BUFFER_STATE state;

      // start main scope
      auto scopes = _ast->scopes();
      scopes->start(arangodb::aql::AQL_SCOPE_MAIN);


      if (hsql_lex_init(&scanner)) {
      // Couldn't initialize the lexer.
      fprintf(stderr, "SQLParser: Error when initializing lexer!\n");
      return false;
    }
    std::string textString = _query->queryString().extract(_query->queryString().length());
    textString = textString.substr(1, textString.size() - 2);

    const char* text =  textString.c_str();
    std::cout << "[SQLParser::parse::text] = " << text << std::endl;
    state = hsql__scan_string(text, scanner);

    // Parse the tokens.
    // If parsing fails, the result will contain an error object.
    int ret = hsql_parse(this, scanner);
    bool success = (ret == 0);
    //result->setIsValid(success);

    hsql__delete_buffer(state, scanner);
    hsql_lex_destroy(scanner);

    return true;
  }

  // static
//  bool SQLParser::parseSQLString(const char* sql, arangodb::aql::Parser* result) {
//    return parse(sql, result);
//  }
//
//  bool SQLParser::parseSQLString(const std::string& sql, arangodb::aql::Parser* result) {
//    return parse(sql, result);
//  }

  // static
  bool SQLParser::tokenize(const std::string& sql, std::vector<int16_t>* tokens) {
    // Initialize the scanner.
    yyscan_t scanner;
    if (hsql_lex_init(&scanner)) {
      fprintf(stderr, "SQLParser: Error when initializing lexer!\n");
      return false;
    }

    YY_BUFFER_STATE state;
    state = hsql__scan_string(sql.c_str(), scanner);

    YYSTYPE yylval;
    YYLTYPE yylloc;

    // Step through the string until EOF is read.
    // Note: hsql_lex returns int, but we know that its range is within 16 bit.
    int16_t token = hsql_lex(&yylval, &yylloc, scanner);
    while (token != 0) {
      tokens->push_back(token);
      token = hsql_lex(&yylval, &yylloc, scanner);

      if (token == SQL_IDENTIFIER || token == SQL_STRING) {
        free(yylval.sval);
      }
    }

    hsql__delete_buffer(state, scanner);
    hsql_lex_destroy(scanner);
    return true;
  }

    /// @brief push a temporary value on the parser's stack
    void SQLParser::pushStack(void* value) { _stack.emplace_back(value); }

} // namespace hsql
