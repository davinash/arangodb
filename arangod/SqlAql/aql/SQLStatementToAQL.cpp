//
// Created by adongre on 10/17/18.
//

#include <iostream>
#include <sstream>
#include "SQLStatementToAQL.h"
#include "../SQLParser.h"
#include "../util/sqlhelper.h"
#include "AQLSelectStatement.h"

namespace hsql {
#define SINGLE_SPACE " "
#define COLUMN_NAME_PREFIX   "ROW"

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

    std::string SQLStatementToAQL::convert(const std::string &query) {
        D(std::cout << "Query = " << query << std::endl;)
        SQLParserResult result;
        SQLParser::parse(query, &result);
        if (result.isValid()) {
            for (auto i = 0u; i < result.size(); ++i) {
                const SQLStatement *stmt = result.getStatement(i);
                switch (stmt->type()) {
                    case kStmtSelect:
                        return convertToSelectAQL(stmt);
                    case kStmtInsert:
                        break;
                    case kStmtCreate:
                        break;
                    case kStmtDelete:
                        break;
                    default:
                        break;
                }
            }

        } else {
            printf("[ SQLStatementToAQL::convert ] -> Invalid Query\n");
        }
        return "ERROR";
    }

    void SQLStatementToAQL::walkOperatorExpression(const Expr *expr, AQLSelectStatement *pAqlSelectStatement,
                                                   std::ostringstream &aqlQuery) {
        if (expr == nullptr) {
            return;
        }

        std::string opString = "";
        switch (expr->opType) {
            case kOpAnd:
                D(std::cout << "----> kOpAnd" << std::endl;)
                opString = "AND";
                break;
            case kOpOr:
                D(std::cout << "----> kOpOr" << std::endl;)
                opString = "OR";
                break;
            case kOpNot:
                D(std::cout << "----> kOpNot" << std::endl;)
                opString = "!=";
                break;
            case kOpEquals:
                D(std::cout << "----> kOpEquals" << std::endl;)
                opString = "==";
                break;
            default:
                //inprintU(expr->opType, numIndent);
                D(std::cout << "----> kDefault" << std::endl;)
                //aqlQuery << "==" << SINGLE_SPACE;
                break;
        }
        walkExpression(expr->expr, pAqlSelectStatement, aqlQuery, true, false);
        if (expr->expr2 != nullptr) {
            aqlQuery << opString << SINGLE_SPACE;
            walkExpression(expr->expr2, pAqlSelectStatement, aqlQuery, true, false);
        } else if (expr->exprList != nullptr) {
            for (Expr *e : *expr->exprList) walkExpression(e, pAqlSelectStatement, aqlQuery, true, false);
        }
    }

    void SQLStatementToAQL::walkExpression(const Expr *expr, AQLSelectStatement *pAqlSelectStatement,
                                           std::ostringstream &aqlQuery,
                                           bool colNamePrefix, bool prefixColumnName) {
        switch (expr->type) {
            case kExprStar:
                D(std::cout << "----> kExprStar" << std::endl;)
                aqlQuery << COLUMN_NAME_PREFIX;
                break;
            case kExprColumnRef:
                D(std::cout << "----> kExprColumnRef" << std::endl;)
                pAqlSelectStatement->getColumnProjections()->push_back(expr->name);
                if (colNamePrefix) {
                    if (prefixColumnName) {
                        aqlQuery << expr->name << " : " << COLUMN_NAME_PREFIX << "." << expr->name << SINGLE_SPACE;
                    } else {
                        aqlQuery << COLUMN_NAME_PREFIX << "." << expr->name << SINGLE_SPACE;
                    }
                } else {
                    aqlQuery << expr->name << SINGLE_SPACE;
                }
                break;
            case kExprLiteralFloat:
                D(std::cout << "----> kExprLiteralFloat" << std::endl;)
                break;
            case kExprLiteralInt:
                D(std::cout << "----> kExprLiteralInt" << std::endl;)
                aqlQuery << expr->ival << SINGLE_SPACE;
                break;
            case kExprLiteralString:
                D(std::cout << "----> kExprLiteralString" << std::endl;)
                aqlQuery << "'" << expr->name << "'" << SINGLE_SPACE;
                break;
            case kExprFunctionRef:
                D(std::cout << "----> kExprFunctionRef" << std::endl;)
                for (Expr *e : *expr->exprList) walkExpression(e, pAqlSelectStatement, aqlQuery, false, false);
                break;
            case kExprOperator:
                D(std::cout << "----> kExprOperator" << std::endl;)
                walkOperatorExpression(expr, pAqlSelectStatement, aqlQuery);
                break;
            case kExprSelect:
                D(std::cout << "----> kExprSelect" << std::endl;)
                walkSelectStatement(expr->select, pAqlSelectStatement, aqlQuery);
                break;
            case kExprParameter:
                D(std::cout << "----> kExprParameter " << std::endl;)
                break;
            case kExprArray:
                D(std::cout << "----> kExprArray" << std::endl;)
                for (Expr *e : *expr->exprList) walkExpression(e, pAqlSelectStatement, aqlQuery, false, false);
                break;
            case kExprArrayIndex:
                D(std::cout << "----> kExprArrayIndex" << std::endl;)
                walkExpression(expr->expr, pAqlSelectStatement, aqlQuery, false, false);
                break;
            default:
                std::cerr << "Unrecognized expression type " << expr->type << std::endl;
                return;
        }
        if (expr->alias != nullptr) {
        }
    }

    void SQLStatementToAQL::walkSelectStatement(const SelectStatement *pStmt,
                                                AQLSelectStatement *pAqlSelectStatement,
                                                std::ostringstream &aqlQuery) {


        if (pStmt->fromTable != nullptr) {
            aqlQuery << "FOR " << COLUMN_NAME_PREFIX << " IN "
                     << pStmt->fromTable->getName() << SINGLE_SPACE;
        }

        if (pStmt->whereClause != nullptr) {
            D(std::cout << "----> Reading WHERE Clause " << std::endl;)
            aqlQuery << "FILTER" << SINGLE_SPACE;
            walkExpression(pStmt->whereClause, pAqlSelectStatement, aqlQuery, false, false);
        }

        if (pStmt->groupBy != nullptr) {
            pAqlSelectStatement->setGroupByExist(true);
        }

        if (pStmt->unionSelect != nullptr) {
        }

        if (pStmt->order != nullptr) {
            D(std::cout << "---> Reading Order by " << std::endl;)
            aqlQuery << "SORT" << SINGLE_SPACE;

            if (pStmt->order->size() >= 2) {
                for (auto i = 0u; i < pStmt->order->size() - 1; i++) {
                    walkExpression(pStmt->order->at(i)->expr, pAqlSelectStatement, aqlQuery, true, false);
                    aqlQuery << "," << SINGLE_SPACE;
                }
                if (pStmt->order->size() != 1) {
                    walkExpression(pStmt->order->at(pStmt->order->size() - 1)->expr, pAqlSelectStatement,
                                   aqlQuery, true, false);
                }
            } else {
                walkExpression(pStmt->order->at(0)->expr, pAqlSelectStatement,
                               aqlQuery, true, false);
            }

        }

        if (pStmt->limit != nullptr) {
        }

        aqlQuery << "RETURN " << "{" << SINGLE_SPACE;
        if (pStmt->selectList->size() >= 2) {
            for (auto i = 0u; i < pStmt->selectList->size() - 1; i++) {
                walkExpression(pStmt->selectList->at(i), pAqlSelectStatement, aqlQuery, true, true);
                aqlQuery << "," << SINGLE_SPACE;
            }
            if (pStmt->selectList->size() != 1) {
                walkExpression(pStmt->selectList->at(pStmt->selectList->size() - 1), pAqlSelectStatement, aqlQuery,
                               true, true);
            }
        } else {
            if (pStmt->selectList->size() == 1) {
                walkExpression(pStmt->selectList->at(0), pAqlSelectStatement, aqlQuery, true, true);
            }
        }

        aqlQuery << " }";
    }

    std::string SQLStatementToAQL::convertToSelectAQL(const SQLStatement *pStatement) {

        SelectStatement *pStmt = (SelectStatement *) pStatement;
        AQLSelectStatement *pAqlSelectStatement = new AQLSelectStatement();
        std::ostringstream aqlQuery;
        walkSelectStatement(pStmt, pAqlSelectStatement, aqlQuery);
        return aqlQuery.str();
    }
}