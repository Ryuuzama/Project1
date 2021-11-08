
#ifndef BRANDNEWPROJECT1_PREDICATE_H
#define BRANDNEWPROJECT1_PREDICATE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Parameter.h"
using namespace std;

class Predicate {
public:
    Predicate(){};
    Predicate(string name, vector<Parameter> preParameter);
    string name;
    vector<Parameter> preParameter;

    const vector<Parameter> &getPreParameter() const;

    string toString();
    void setName(string newName) {
        name = newName;
    }
    void convertParameter(string newString) {
        Parameter parameter(newString);
        preParameter.push_back(parameter);
    }
    void addParameter(Parameter newParameter) {
        preParameter.push_back(newParameter);
    }
    string getName() {
        return name;
    }
    vector<Parameter> GetParameters(){
        return preParameter;
    }

};


#endif //BRANDNEWPROJECT1_PREDICATE_H
