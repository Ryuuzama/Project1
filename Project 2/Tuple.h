#ifndef BRANDNEWPROJECT1_TUPLE_H
#define BRANDNEWPROJECT1_TUPLE_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "Parameter.h"
using namespace std;
class Tuple {
public:
    Tuple(){}
    vector<string> values;
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
    void setTuple (vector<Parameter> facts) {
        for (unsigned int i = 0; i < facts.size(); i++) {
            values.push_back(facts.at(i).toString());
        }
    };
    vector<string> getVector(){
        return values;
    }
};


#endif //BRANDNEWPROJECT1_TUPLE_H
