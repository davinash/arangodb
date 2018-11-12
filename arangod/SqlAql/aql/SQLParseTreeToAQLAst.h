//
// Created by adongre on 11/2/18.
//

#ifndef ARANGODB3_SQLPARSETREETOAQLAST_H
#define ARANGODB3_SQLPARSETREETOAQLAST_H

#include "../SQLParser.h"
#include "../sql/SelectStatement.h"

namespace hsql {
    class SQLParseTreeToAQLAst {
    public:
        SQLParseTreeToAQLAst(SQLParser* parser, SelectStatement* statement);
        void generateAqlAstForSelectStatement();
    private:
        SQLParser* _parser;
        SelectStatement* _statement;

        arangodb::aql::AstNode * createNodeFromVariable(const char* variableName);
        void createReturnNode();
        arangodb::aql::AstNode* createReturnNodeInternal();
        void createReturnNodeForStar();
        void createReturnNodeForColumn(const char *columnName, arangodb::aql::AstNode* node);
    };
}


#endif //ARANGODB3_SQLPARSETREETOAQLAST_H
