//
// Created by adongre on 11/2/18.
//

#include <iostream>
#include "SQLParseTreeToAQLAst.h"
#include "../../Aql/AstNode.h"

namespace hsql {
    SQLParseTreeToAQLAst::SQLParseTreeToAQLAst(SQLParser *parser, SelectStatement *statement)
            : _parser(parser),
              _statement(statement) {}

    void SQLParseTreeToAQLAst::generateAQLAST() {
        std::cout << "SQLParseTreeToAQLAst::generateAQLAST" << std::endl;

        auto ast = _parser->ast();
        arangodb::aql::AstNode *nodeDataSource = nullptr;
        auto const &resolver = _parser->query()->resolver();
        nodeDataSource = ast->createNodeDataSource(resolver, TRI_CHAR_LENGTH_PAIR(_statement->fromTable->getName()),
                                                   arangodb::AccessMode::Type::READ, true, false);

        _parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);

        arangodb::aql::AstNode *variableNode = _parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        arangodb::aql::Variable *variable = static_cast<arangodb::aql::Variable *>(variableNode->getData());

        _parser->ast()->addOperation(_parser->ast()->createNodeFor(variable, nodeDataSource, nullptr));

        auto nodeObject = _parser->ast()->createNodeObject();
        _parser->pushStack(nodeObject);

        auto variableR = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        if (variableR == nullptr) {
            std::cerr << "variable does not exist" << std::endl;
        }
        // create a reference to the variable
        auto nodeRef = ast->createNodeReference(variableR);
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR("ROW"), nodeRef);

        auto nodeRef1 = static_cast<arangodb::aql::AstNode *>(_parser->popStack());

        auto nodeR2 = _parser->ast()->createNodeReturn(nodeRef1);
        _parser->ast()->addOperation(nodeR2);
        _parser->ast()->scopes()->endNested();

    }
}