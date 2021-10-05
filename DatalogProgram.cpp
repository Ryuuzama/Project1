//
// Created by Daniel Steffen on 9/29/21.
//

#include "DatalogProgram.h"
#include <vector>
#include <sstream>
using namespace std;

// constructor!
/*DatalogProgram::DatalogProgram(vector<Predicate> schemesVector, vector<Predicate> factsVector, vector<Predicate> queriesVector, vector<Rules> rulesVector){
    this->schemesVector = schemesVector;
    this->factsVector = factsVector;
    this->queriesVector = queriesVector;
    this->rulesVector = rulesVector;
}*/

string DatalogProgram::toString() {
        ostringstream os;
        os << "Success!" << endl;
        os << "Schemes(" << schemesVector.size() << "):" << endl;
        for (unsigned int i = 0; i < schemesVector.size(); i++) {
            os << schemesVector.at(i).toString() << endl;
        }

        os << "Facts(" << factsVector.size() << "):" << endl;
        for (unsigned int i = 0; i < factsVector.size(); i++) {
            os << factsVector.at(i).toString() << endl;
            for (unsigned int j = 0; j < factsVector.at(i).GetParameters().size(); j++) {
                Domain.insert(factsVector.at(i).GetParameters().at(j).toString());
            }
        }
        //add stuff to domain
        os << "Rules(" << rulesVector.size() << "):" << endl;
    for (unsigned int i = 0; i < rulesVector.size(); i++) {
        os << rulesVector.at(i).toString() << endl;
    }
        os << "Queries(" << queriesVector.size() << "):" << endl;
    for (unsigned int i = 0; i < queriesVector.size(); i++) {
        os << queriesVector.at(i).toString() << endl;
    }
        os << "Domain(";
        for (string s : Domain) {
            os << s << endl;
        }

        return os.str();
}