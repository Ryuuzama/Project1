//
// Created by Daniel Steffen on 9/29/21.
//

#ifndef BRANDNEWPROJECT1_RULES_H
#define BRANDNEWPROJECT1_RULES_H

#include "Predicate.h"

class Rules {
public:
    Rules(Predicate headPredicate, vector<Predicate> multiplePredicates);
    vector <Predicate> multiplePredicates;
    Predicate headPredicate;
    string toString();
};


#endif //BRANDNEWPROJECT1_RULES_H
