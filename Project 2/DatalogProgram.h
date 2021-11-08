
#ifndef BRANDNEWPROJECT1_DATALOGPROGRAM_H
#define BRANDNEWPROJECT1_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rules.h"
#include <set>

class DatalogProgram {

public:
    DatalogProgram(){}
    //DatalogProgram(vector<Predicate> schemesVector, vector<Predicate> factsVector, vector<Predicate> queriesVector, vector<Rules> rulesVector);
    vector<Predicate> schemesVector;
    vector<Predicate> factsVector;
    vector<Predicate> queriesVector;
    vector<Rules> rulesVector;
    set <string> Domain;
    string toString();
    void setSchemesVector (Predicate predicate) {
        schemesVector.push_back(predicate);
    }
    void setFactsVector (Predicate predicate) {
        factsVector.push_back(predicate);
    }
    void setQueriesVector (Predicate predicate) {
        queriesVector.push_back(predicate);
    }
    void setRulesVector (Rules rules) {
        rulesVector.push_back(rules);
    }

    const vector<Predicate> &getSchemesVector() const;

    const vector<Predicate> &getFactsVector() const;

    const vector<Predicate> &getQueriesVector() const;

    const vector<Rules> &getRulesVector() const;


};


#endif //BRANDNEWPROJECT1_DATALOGPROGRAM_H
