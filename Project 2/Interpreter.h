#ifndef BRANDNEWPROJECT1_INTERPRETER_H
#define BRANDNEWPROJECT1_INTERPRETER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "DatalogProgram.h"
#include "Database.h"
using namespace std;
class Interpreter {
public:
    Interpreter(DatalogProgram datalogProgram);
    void Interpret();
    Relation evaluatePredicate(Predicate p);
    void evaluateAllQueries();
    void evaluateRules();
    bool evaluateRule(Rules rule);

private:
    DatalogProgram newDatalogProgram;
    Database newDatabase;
    Relation newRelation;
    Header newHeader;
    int index1;
};


#endif //BRANDNEWPROJECT1_INTERPRETER_H
