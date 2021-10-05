//
// Created by Daniel Steffen on 9/29/21.
//

#include "Rules.h"
#include <sstream>
using namespace std;

Rules::Rules(Predicate headPredicate, vector<Predicate> multiplePredicates) {
    this->headPredicate = headPredicate;
    this->multiplePredicates = multiplePredicates;
}

string Rules::toString() {
    ostringstream os;
    os << headPredicate.toString() << " :- ";
    for (unsigned int i = 0; i < multiplePredicates.size(); i++) {
        if (i != multiplePredicates.size()-1) {
            os << multiplePredicates.at(i).Predicate::toString() << ",";
        }
        else {
            os << multiplePredicates.at(i).Predicate::toString();
        }
    }
    return os.str();
}
