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
        void generateAQLAST();
    private:
        SQLParser* _parser;
        SelectStatement* _statement;
    };
}


#endif //ARANGODB3_SQLPARSETREETOAQLAST_H
