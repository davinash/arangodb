//
// Created by adongre on 10/17/18.
//

#ifndef SQL_PARSER_SELECTSTATEMENTTOAQL_H
#define SQL_PARSER_SELECTSTATEMENTTOAQL_H


#include <string>
#include <sstream>
#include "../sql/SQLStatement.h"
#include "../sql/Table.h"

namespace hsql {
    class SQLStatementToAQL {
    public:
        static std::string convert(const std::string &sql);

        static std::string convertToSelectAQL(const SQLStatement *pStatement);

        static void
        walkSelectStatement(const SelectStatement *pStmt, std::ostringstream &aqlQuery, int &level, bool isJoinQuery);

        static void walkExpression(const Expr *expr, std::ostringstream &aqlQuery, bool iscolNamePrefix, int &level,
                bool isJoinQuery, bool decorateColumnName);

        static void walkOperatorExpression(const Expr *expr, std::ostringstream &aqlQuery, int &level, bool isJoinQuery);

        static void walkTableRefInfo(hsql::TableRef *table, std::ostringstream &aqlQuery, int &level, bool isJoinQuery);
    };
}


#endif //SQL_PARSER_SELECTSTATEMENTTOAQL_H
