//
// Created by Daniel Steffen on 9/29/21.
//

#include "Predicate.h"
#include "Parser.h"
#include <sstream>

Predicate::Predicate(string name, vector<Parameter> preParameters){
    this->name = name;
    this->preParameter = preParameters;
}

string Predicate::toString() {
    // ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    ostringstream os;
    os << name << "(";
    for (unsigned int i = 0; i < preParameter.size(); i++) {
        if (i != preParameter.size()) {
            os << preParameter.at(i).toString() << ",";
        }
        else {
            os << preParameter.at(i).toString();
        }
    }
    os << ")";
    return os.str();

}