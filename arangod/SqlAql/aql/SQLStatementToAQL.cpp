
//
// Created by adongre on 10/17/18.
//

#include <iostream>
#include <sstream>
#include "SQLStatementToAQL.h"
#include "../SQLParser.h"


#ifdef DEBUG_BUILD
#define DEBUG(x) do { std::cout << x << std::endl; } while (0)
#else
#define DEBUG(x)
#endif


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
                DEBUG("-----> walkOperatorExpression::kOpAnd ");
                opString = "AND";
                break;
            case kOpOr:
                DEBUG ("-----> walkOperatorExpression::kOpOr ");
                opString = "OR";
                break;
            case kOpNot:
                DEBUG("-----> walkOperatorExpression::kOpNot ");
                opString = "!=";
                break;
            case kOpEquals:
                DEBUG("-----> walkOperatorExpression::kOpEquals ");
                opString = "==";
                break;
            default:
                break;
        }
        DEBUG("-----> walkExpression with " << level);
        walkExpression(expr->expr, aqlQuery, true, level, isJoinQuery, false);
        if (isJoinQuery) {
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
                DEBUG("-----> walkExpression::kExprColumnRef " << expr->name);
                if (colNamePrefix) {
                    if (isJoinQuery) {
                        if (decorateColumnName) {
                            aqlQuery << expr->name << " : " << COLUMN_NAME_PREFIX << level << "." << expr->name
                                     << SINGLE_SPACE;
                        } else {
                            aqlQuery << COLUMN_NAME_PREFIX << level << "." << expr->name << SINGLE_SPACE;
                        }
                    } else {
                        if (decorateColumnName) {
                            aqlQuery << expr->name << " : " << COLUMN_NAME_PREFIX << "." << expr->name << SINGLE_SPACE;
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
                DEBUG("-----> walkExpression::kExprLiteralFloat");
                break;
            case kExprLiteralInt:
                DEBUG("-----> walkExpression::kExprLiteralInt");
                aqlQuery << expr->ival << SINGLE_SPACE;
                break;
            case kExprLiteralString:
                DEBUG("-----> walkExpression::kExprLiteralString");
                aqlQuery << "'" << expr->name << "'" << SINGLE_SPACE;
                break;
            case kExprFunctionRef:
                DEBUG("-----> walkExpression::kExprFunctionRef");
                for (Expr *e : *expr->exprList) walkExpression(e, aqlQuery, false, level, isJoinQuery, false);
                break;
            case kExprOperator:
                DEBUG("-----> walkExpression::kExprOperator");
                walkOperatorExpression(expr, aqlQuery, level, isJoinQuery);
                break;
            case kExprSelect:
                DEBUG("-----> walkExpression::kExprArray");
                walkSelectStatement(expr->select, aqlQuery, level, isJoinQuery);
                break;
            case kExprParameter:
                DEBUG("-----> walkExpression::kExprParameter");
                break;
            case kExprArray:
                DEBUG("-----> walkExpression::kExprArray");
                for (Expr *e : *expr->exprList) walkExpression(e, aqlQuery, false, level, isJoinQuery, false);
                break;
            case kExprArrayIndex:
                DEBUG("-----> walkExpression::kExprArrayIndex");
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
                DEBUG("JOIN FILTER CONDITION");
                aqlQuery << " FILTER ";
                level = 0;
                walkExpression(table->join->condition, aqlQuery, true, level, true, false);
                DEBUG("JOIN FILTER CONDITION DONE ");
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

    std::string SQLStatementToAQL::convertToSelectAQL(const SelectStatement *pStatement) {

        std::ostringstream aqlQuery;
        int level = 0;
        walkSelectStatement(pStatement, aqlQuery, level, false);
        return aqlQuery.str();
    }

    void SQLStatementToAQL::walkInsertStatement(const InsertStatement *pStatement, std::ostringstream &aqlQuery) {
        aqlQuery << "INSERT  { ";
        if (pStatement->columns != nullptr) {
        }
        switch (pStatement->type) {
            case kInsertValues: {
                std::vector<Expr *> v = *pStatement->values;
                std::vector<char *> c = *pStatement->columns;
                int level = 0;
                for (auto i = 0u; i < v.size(); i++) {
                    if (i != 0) {
                        aqlQuery << " , ";
                    }
                    aqlQuery << c.at(i) << ": ";
                    walkExpression(v.at(i), aqlQuery, true, level, false, false);
                }
                aqlQuery << " } ";
                aqlQuery << "INTO " << pStatement->tableName;
            }
                break;
            case kInsertSelect:
                break;
        }
    }

    std::string SQLStatementToAQL::convertToInsertAQL(const InsertStatement *pStatement) {
        std::ostringstream aqlQuery;
        walkInsertStatement(pStatement, aqlQuery);
        return aqlQuery.str();
    }


    std::string SQLStatementToAQL::convert(const std::string &query) {
        DEBUG("Query = " << query);
        SQLParserResult result;
        SQLParser::parse(query, &result);
        if (result.isValid()) {
            for (auto i = 0u; i < result.size(); ++i) {
                const SQLStatement *stmt = result.getStatement(i);
                switch (stmt->type()) {
                    case kStmtSelect:
                        return convertToSelectAQL((SelectStatement *) stmt);
                    case kStmtInsert:
                        return convertToInsertAQL((InsertStatement *) stmt);
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
