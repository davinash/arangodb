//
// Created by adongre on 10/19/18.
//

#include "AQLSelectStatement.h"

namespace hsql {

    AQLSelectStatement::AQLSelectStatement() :
            tableName(""),
            pColumnProjections(new std::vector<std::string>()),
            whereClauseExists(false),
            groupByExists(false) {};

    AQLSelectStatement::~AQLSelectStatement() {
        delete pColumnProjections;
    }

    std::string AQLSelectStatement::createAQLQuery() {
        std::string aqlQuery = "FOR U IN " + tableName;
        if (false == whereClauseExists && pColumnProjections->size() == 0) {
        }
        return aqlQuery;
    }
}