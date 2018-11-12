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


    void SQLParseTreeToAQLAst::createDataSourceNode() {
        std::cout << "SQLParseTreeToAQLAst::createDataSourceNode" << std::endl;
        arangodb::aql::AstNode *nodeDataSource = nullptr;
        auto const &resolver = _parser->query()->resolver();
        nodeDataSource = _parser->ast()->createNodeDataSource(resolver,
                                                              TRI_CHAR_LENGTH_PAIR(_statement->fromTable->getName()),
                                                              arangodb::AccessMode::Type::READ, true, false);
        arangodb::aql::AstNode *variableNode = _parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        arangodb::aql::Variable *variable = static_cast<arangodb::aql::Variable *>(variableNode->getData());
        _parser->ast()->addOperation(_parser->ast()->createNodeFor(variable, nodeDataSource, nullptr));
    }


    void SQLParseTreeToAQLAst::createReturnNodeForStar() {
        auto variable = _parser->ast()->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        if (variable == nullptr) {
            std::cerr << "variable does not exist" << std::endl;
        }
        auto nodeRef = _parser->ast()->createNodeReference(variable);
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR("ROW"), nodeRef);
    }

    void SQLParseTreeToAQLAst::createReturnNodeForColumn(const char *columnName, arangodb::aql::AstNode* node) {
        std::cout << "SQLParseTreeToAQLAst::createReturnNodeForColumn::column Name :: " << columnName << std::endl;
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR(columnName), node);
    }


    void SQLParseTreeToAQLAst::createReturnNode(const Expr *expr, arangodb::aql::AstNode* node) {
        switch (expr->type) {
            case kExprStar: {
                createReturnNodeForStar();
                break;
            }
            case kExprColumnRef: {
                createReturnNodeForColumn(expr->name, node);
                //_parser->popStack();
                break;
            }
            default:
                std::cout << "Column type not handled yet " << std::endl;
        }
    }

    void SQLParseTreeToAQLAst::createReturnNode() {
        std::cout << "SQLParseTreeToAQLAst::createReturnNode" << std::endl;
        auto nodeObject = _parser->ast()->createNodeObject();
        _parser->pushStack(nodeObject);

        arangodb::aql::AstNode* node = _parser->ast()->createNodeObject();
        _parser->pushStack(node);

        for (auto index = 0u; index < _statement->selectList->size(); index++) {
            createReturnNode(_statement->selectList->at(index), node);
        }

        auto nodeRef1 = static_cast<arangodb::aql::AstNode *>(_parser->popStack());
        auto nodeR2 = _parser->ast()->createNodeReturn(nodeRef1);
        _parser->ast()->addOperation(nodeR2);

    }

    void SQLParseTreeToAQLAst::generateAQLAST() {
        std::cout << "SQLParseTreeToAQLAst::generateAQLAST" << std::endl;

        _parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
        createDataSourceNode();
        createReturnNode();
        _parser->ast()->scopes()->endNested();

    }
}