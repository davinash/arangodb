//
// Created by adongre on 10/17/18.
//

#ifndef SQL_PARSER_SELECTSTATEMENTTOAQL_H
#define SQL_PARSER_SELECTSTATEMENTTOAQL_H


#include <string>
#include <sstream>
#include "../sql/SQLStatement.h"
#include "AQLSelectStatement.h"

namespace  hsql {
    class SQLStatementToAQL {
    public:
        static std::string convert(const std::string &sql);

        static std::string convertToSelectAQL(const SQLStatement *pStatement);

        static void walkSelectStatement(const SelectStatement *pStmt, AQLSelectStatement *, std::ostringstream& aqlQuery);

        static void walkExpression(const Expr *expr, AQLSelectStatement *, std::ostringstream& aqlQuery,
                bool iscolNamePrefix, bool prefixColumnName);

        static void walkOperatorExpression(const Expr *expr, AQLSelectStatement *pAqlSelectStatement, std::ostringstream& aqlQuery);
    };
}


#endif //SQL_PARSER_SELECTSTATEMENTTOAQL_H
