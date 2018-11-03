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
        arangodb::aql::AstNode *node = nullptr;
        auto variable = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR(_statement->fromTable->getName()), true);
        if (variable == nullptr) {
            if (ast->scopes()->canUseCurrentVariable() && strcmp(_statement->fromTable->getName(), "CURRENT") == 0) {
                variable = ast->scopes()->getCurrentVariable();
            } else if (strcmp(_statement->fromTable->getName(), arangodb::aql::Variable::NAME_CURRENT) == 0) {
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
            node = ast->createNodeDataSource(resolver, TRI_CHAR_LENGTH_PAIR(_statement->fromTable->getName()),
                                             arangodb::AccessMode::Type::READ, true, false);
        }


        _parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
        _parser->pushStack(_parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true));

        arangodb::aql::AstNode* variableNode = static_cast<arangodb::aql::AstNode*>(_parser->popStack());
        TRI_ASSERT(variableNode != nullptr);
        arangodb::aql::Variable* variable1 = static_cast<arangodb::aql::Variable*>(variableNode->getData());
        arangodb::aql::AstNode* node1 = nullptr;
        arangodb::aql::AstNode* search = nullptr;
        arangodb::aql::AstNode* options = nullptr;
        node1 = _parser->ast()->createNodeFor(variable1, node, options);
        _parser->ast()->addOperation(node1);

        auto nodeR = _parser->ast()->createNodeObject();
        _parser->pushStack(nodeR);

        auto astR = _parser->ast();
        auto variableR = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        if (variableR == nullptr) {
            std::cerr << "variable does not exist" << std::endl;
        }
        // create a reference to the variable
        auto nodeRef = ast->createNodeReference(variableR);
        _parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR("ROW"), nodeRef);

        auto nodeRef1 = static_cast<arangodb::aql::AstNode*>(_parser->popStack());

        auto nodeR2 = _parser->ast()->createNodeReturn(nodeRef1);
        _parser->ast()->addOperation(nodeR2);
        _parser->ast()->scopes()->endNested();


//        arangodb::aql::AstNode *variableNode = static_cast<arangodb::aql::AstNode *>(_parser->popStack());
//        TRI_ASSERT(variableNode != nullptr);
//        arangodb::aql::AstNode *nodeOp = nullptr;
//        arangodb::aql::AstNode *options = nullptr;
//        nodeOp = _parser->ast()->createNodeFor(static_cast<arangodb::aql::Variable *>(variableNode->getData()),
//                                               node, options);
//        _parser->ast()->addOperation(nodeOp);
//
//        _parser->ast()->addOperation(_parser->ast()->createNodeReturn(_parser->ast()->createNodeObject()));
//        _parser->ast()->scopes()->endNested();


    }
}