//
// Created by adongre on 10/17/18.
//

#include <iostream>
#include <sstream>
#include "SQLStatementToAQL.h"
#include "../SQLParser.h"


namespace hsql {
#define SINGLE_SPACE " "
#define COLUMN_NAME_PREFIX   "ROW"

    void SQLStatementToAQL::walkOperatorExpression(const Expr *expr, std::ostringstream &aqlQuery, int &level,
                                                   bool isJoinQuery) {
        if (expr == nullptr) {
            return;
        }

        std::string opString = "";
        switch (expr->opType) {
            case kOpAnd:
                std::cout << "-----> walkOperatorExpression::kOpAnd " << std::endl;
                opString = "AND";
                break;
            case kOpOr:
                std::cout << "-----> walkOperatorExpression::kOpOr " << std::endl;
                opString = "OR";
                break;
            case kOpNot:
                std::cout << "-----> walkOperatorExpression::kOpNot " << std::endl;
                opString = "!=";
                break;
            case kOpEquals:
                std::cout << "-----> walkOperatorExpression::kOpEquals " << std::endl;
                opString = "==";
                break;
            default:
                break;
        }
        std::cout << "-----> walkExpression with " << level << std::endl;
        walkExpression(expr->expr, aqlQuery, true, level, isJoinQuery, false);
        if ( isJoinQuery ) {
            level++;
        }
        if (expr->expr2 != nullptr) {
            aqlQuery << opString << SINGLE_SPACE;
            walkExpression(expr->expr2, aqlQuery, true, level, isJoinQuery, false);
        } else if (expr->exprList != nullptr) {
            for (Expr *e : *expr->exprList) walkExpression(e, aqlQuery, true, level, isJoinQuery, false);
        }
    }

    void SQLStatementToAQL::walkExpression(const Expr *expr, std::ostringstream &aqlQuery,
                                           bool colNamePrefix, int &level, bool isJoinQuery, bool decorateColumnName) {
        switch (expr->type) {
            case kExprStar:
                if (level != 0) {
                    for (int i = 0; i <= level; i++) {
                        if (i != 0) {
                            aqlQuery << ",";
                        }
                        aqlQuery << COLUMN_NAME_PREFIX << i;
                    }
                } else {
                    aqlQuery << COLUMN_NAME_PREFIX;
                }
                break;
            case kExprColumnRef:
                std::cout << "-----> walkExpression::kExprColumnRef " << expr->name << std::endl;
                if (colNamePrefix) {
                    if (isJoinQuery) {
                        if ( decorateColumnName) {
                            aqlQuery << expr->name << " : " << COLUMN_NAME_PREFIX << level << "." << expr->name << SINGLE_SPACE;
                        } else {
                            aqlQuery << COLUMN_NAME_PREFIX << level << "." << expr->name << SINGLE_SPACE;
                        }
                    } else {
                        if ( decorateColumnName) {
                            aqlQuery << expr->name << " : "  << COLUMN_NAME_PREFIX << "." << expr->name << SINGLE_SPACE;
                        } else {
                            aqlQuery << COLUMN_NAME_PREFIX << "." << expr->name << SINGLE_SPACE;
                        }
                    }
                } else {
                    if (isJoinQuery) {
                        aqlQuery << expr->name << level << SINGLE_SPACE;
                    } else {
                        aqlQuery << expr->name << SINGLE_SPACE;
                    }
                }
                break;
            case kExprLiteralFloat:
                std::cout << "-----> walkExpression::kExprLiteralFloat" << std::endl;
                break;
            case kExprLiteralInt:
                std::cout << "-----> walkExpression::kExprLiteralInt" << std::endl;
                aqlQuery << expr->ival << SINGLE_SPACE;
                break;
            case kExprLiteralString:
                std::cout << "-----> walkExpression::kExprLiteralString" << std::endl;
                aqlQuery << "'" << expr->name << "'" << SINGLE_SPACE;
                break;
            case kExprFunctionRef:
                std::cout << "-----> walkExpression::kExprFunctionRef" << std::endl;
                for (Expr *e : *expr->exprList) walkExpression(e, aqlQuery, false, level, isJoinQuery, false);
                break;
            case kExprOperator:
                std::cout << "-----> walkExpression::kExprOperator" << std::endl;
                walkOperatorExpression(expr, aqlQuery, level, isJoinQuery);
                break;
            case kExprSelect:
                std::cout << "-----> walkExpression::kExprArray" << std::endl;
                walkSelectStatement(expr->select, aqlQuery, level, isJoinQuery);
                break;
            case kExprParameter:
                std::cout << "-----> walkExpression::kExprParameter" << std::endl;
                break;
            case kExprArray:
                std::cout << "-----> walkExpression::kExprArray" << std::endl;
                for (Expr *e : *expr->exprList) walkExpression(e, aqlQuery, false, level, isJoinQuery, false);
                break;
            case kExprArrayIndex:
                std::cout << "-----> walkExpression::kExprArrayIndex" << std::endl;
                walkExpression(expr->expr, aqlQuery, false, level, isJoinQuery, false);
                break;
            default:
                std::cerr << "Unrecognized expression type " << expr->type << std::endl;
                return;
        }
        if (expr->alias != nullptr) {
        }
    }

    void SQLStatementToAQL::walkTableRefInfo(TableRef *table, std::ostringstream &aqlQuery,
                                             int &level, bool isJoinQuery) {
        switch (table->type) {
            case kTableName:
                if (isJoinQuery) {
                    aqlQuery << "FOR " << COLUMN_NAME_PREFIX << level << " IN "
                             << table->name << SINGLE_SPACE;
                } else {
                    aqlQuery << "FOR " << COLUMN_NAME_PREFIX << " IN "
                             << table->name << SINGLE_SPACE;
                }
                break;
            case kTableSelect:
                break;
            case kTableJoin:
                walkTableRefInfo(table->join->left, aqlQuery, level, true);
                level++;
                walkTableRefInfo(table->join->right, aqlQuery, level, true);
                std::cout << "JOIN FILTER CONDITION" << std::endl;
                aqlQuery << " FILTER ";
                level = 0;
                walkExpression(table->join->condition, aqlQuery, true, level, true, false);
                std::cout << "JOIN FILTER CONDITION DONE " << std::endl;
                break;
            case kTableCrossProduct:
                break;
        }

        if (table->alias) {
        }
    }

    void SQLStatementToAQL::walkSelectStatement(const SelectStatement *pStmt,
                                                std::ostringstream &aqlQuery, int &level, bool isJoinQuery) {
        if (pStmt->fromTable != nullptr) {
            walkTableRefInfo(pStmt->fromTable, aqlQuery, level, false);
        }

        if (pStmt->whereClause != nullptr) {
            aqlQuery << "FILTER" << SINGLE_SPACE;
            walkExpression(pStmt->whereClause, aqlQuery, false, level, isJoinQuery, false);
        }

        if (pStmt->groupBy != nullptr) {
        }

        if (pStmt->unionSelect != nullptr) {
        }

        if (pStmt->order != nullptr) {
            aqlQuery << "SORT" << SINGLE_SPACE;
            for (auto i = 0u; i < pStmt->order->size(); i++) {
                if (i != 0) {
                    aqlQuery << "," << SINGLE_SPACE;
                }
                walkExpression(pStmt->order->at(i)->expr, aqlQuery, true, level, isJoinQuery, false);
            }
        }

        if (pStmt->limit != nullptr) {
            aqlQuery << " LIMIT " << pStmt->limit->limit << SINGLE_SPACE;
        }

        aqlQuery << "RETURN ";
        if (level != 0) {
            aqlQuery << " MERGE (" << SINGLE_SPACE;
        } else {
            aqlQuery << "{" << SINGLE_SPACE;
        }
        for (auto i = 0u; i < pStmt->selectList->size(); i++) {
            if (i != 0) {
                aqlQuery << "," << SINGLE_SPACE;
            }
            walkExpression(pStmt->selectList->at(i), aqlQuery, true, level, isJoinQuery, true);
        }
        if (level != 0) {
            aqlQuery << " )" << SINGLE_SPACE;
        } else {
            aqlQuery << " }" << SINGLE_SPACE;
        }
    }

    std::string SQLStatementToAQL::convertToSelectAQL(const SQLStatement *pStatement) {

        SelectStatement *pStmt = (SelectStatement *) pStatement;
        std::ostringstream aqlQuery;
        int level = 0;
        walkSelectStatement(pStmt, aqlQuery, level, false);
        return aqlQuery.str();
    }


    std::string SQLStatementToAQL::convert(const std::string &query) {
        std::cout << "Query = " << query << std::endl;
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
        return "";
    }
}