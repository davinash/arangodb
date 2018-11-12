//
// Created by adongre on 11/2/18.
//

#include <iostream>
#include "SQLParseTreeToAQLAst.h"
#include "../../Aql/AstNode.h"

namespace hsql {
    SQLParseTreeToAQLAst::SQLParseTreeToAQLAst(SQLParser *parser, SelectStatement *statement)
            : _parser(parser),
              _statement(statement) {
        //_parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
    }


    arangodb::aql::AstNode *SQLParseTreeToAQLAst::createNodeFromVariable(const char *variableName) {
        std::cout << "SQLParseTreeToAQLAst::createDataSourceNode" << std::endl;
        auto ast = _parser->ast();
        arangodb::aql::AstNode *node = nullptr;
        auto variable = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR(variableName), true);

        if (variable == nullptr) {
            if (ast->scopes()->canUseCurrentVariable() && strcmp(variableName, "CURRENT") == 0) {
                variable = ast->scopes()->getCurrentVariable();
            } else if (strcmp(variableName, arangodb::aql::Variable::NAME_CURRENT) == 0) {
                variable = ast->scopes()->getCurrentVariable();
            }
        }

        if (variable != nullptr) {
            // variable alias exists, now use it
            node = ast->createNodeReference(variable);
        }

        if (node == nullptr) {
            // variable not found. so it must have been a collection or view
            auto const &resolver = _parser->query()->resolver();
            node = ast->createNodeDataSource(resolver, TRI_CHAR_LENGTH_PAIR(variableName),
                                             arangodb::AccessMode::Type::READ, true, false);
        }

        TRI_ASSERT(node != nullptr);
        return node;

    }


    void SQLParseTreeToAQLAst::createReturnNodeForStar() {
        auto ast = _parser->ast();
        auto variable = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        if (variable == nullptr) {
            std::cerr << "variable does not exist" << std::endl;
        }
        // create a reference to the variable
        auto node = ast->createNodeReference(variable);
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR("ROW"), node);
    }

    void SQLParseTreeToAQLAst::createReturnNodeForColumn(const char *columnName, arangodb::aql::AstNode *node) {
        std::cout << "SQLParseTreeToAQLAst::createReturnNodeForColumn::column Name :: " << columnName << std::endl;
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR(columnName), node);
    }


    arangodb::aql::AstNode* SQLParseTreeToAQLAst::createReturnNodeInternal() {

        arangodb::aql::AstNode *node = nullptr;
        for (auto index = 0u; index < _statement->selectList->size(); index++) {
            const Expr *expr = _statement->selectList->at(index);
            switch (expr->type) {
                case kExprStar: {
                    createReturnNodeForStar();
                    node = static_cast<arangodb::aql::AstNode *>(_parser->popStack());
                    break;
                }
                case kExprColumnRef: {
                    arangodb::aql::AstNode *nodeV = createNodeFromVariable(expr->name);
                    if (nodeV->type == arangodb::aql::NODE_TYPE_EXPANSION) {
                        auto current = const_cast<arangodb::aql::AstNode *>
                        (_parser->ast()->findExpansionSubNode(nodeV));
                        TRI_ASSERT(current->type == arangodb::aql::NODE_TYPE_EXPANSION);
                        current->changeMember(1,
                                              _parser->ast()->createNodeAttributeAccess(current->getMember(1),
                                              TRI_CHAR_LENGTH_PAIR(expr->name)));
                        node = nodeV;
                    } else {
                        node = _parser->ast()->createNodeAttributeAccess(nodeV, TRI_CHAR_LENGTH_PAIR(expr->name));
                    }

                    break;
                }
                default:
                    std::cout << "Column type not handled yet " << std::endl;
            }
        }
        return node;
    }

    void SQLParseTreeToAQLAst::createReturnNode() {
        std::cout << "SQLParseTreeToAQLAst::createReturnNode" << std::endl;

        arangodb::aql::AstNode *nodeObject = _parser->ast()->createNodeObject();
        _parser->pushStack(nodeObject);

        arangodb::aql::AstNode *nodeRI = nullptr;
        for (auto index = 0u; index < _statement->selectList->size(); index++) {
            nodeRI = createReturnNodeInternal();
        }

        auto node = _parser->ast()->createNodeReturn(nodeRI);
        _parser->ast()->addOperation(node);
        _parser->ast()->scopes()->endNested();
    }

    void SQLParseTreeToAQLAst::generateAqlAstForSelectStatement() {
        std::cout << "SQLParseTreeToAQLAst::generateAqlAst" << std::endl;
        arangodb::aql::AstNode *nodeVariable = createNodeFromVariable(_statement->fromTable->getName());
        // first open a new scope
        _parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
        _parser->pushStack(_parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true));

        arangodb::aql::AstNode *variableNode = static_cast<arangodb::aql::AstNode *>(_parser->popStack());
        TRI_ASSERT(variableNode != nullptr);
        arangodb::aql::Variable *variable = static_cast<arangodb::aql::Variable *>(variableNode->getData());

        arangodb::aql::AstNode *node = _parser->ast()->createNodeFor(variable, nodeVariable, nullptr);
        _parser->ast()->addOperation(node);

        createReturnNode();
    }
}