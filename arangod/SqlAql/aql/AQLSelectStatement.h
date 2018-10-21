//
// Created by adongre on 10/19/18.
//

#ifndef SQL_PARSER_AQLSELECTSTATEMENT_H
#define SQL_PARSER_AQLSELECTSTATEMENT_H

#include <string>
#include <vector>

namespace hsql {
    class AQLSelectStatement {
    private:
        std::string tableName;
        std::vector<std::string> *pColumnProjections;
        bool whereClauseExists;
        bool groupByExists;
    public:
        AQLSelectStatement();

        ~AQLSelectStatement();

        inline std::vector<std::string> *getColumnProjections() {
            return pColumnProjections;
        }

        std::string getTableName();

        inline void setWhereClauseExist(bool whereClauseExists) {
            this->whereClauseExists = whereClauseExists;
        }

        inline void setGroupByExist(bool groupByExists) {
            this->groupByExists = groupByExists;
        }

        inline bool isQueryWithWhereClause() {
            return whereClauseExists;
        }

        inline bool isQueryWithGroupBy() {
            return groupByExists;
        }

        std::string createAQLQuery();
    };
}


#endif //SQL_PARSER_AQLSELECTSTATEMENT_H
