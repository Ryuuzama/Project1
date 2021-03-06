#ifndef BRANDNEWPROJECT1_HEADER_H
#define BRANDNEWPROJECT1_HEADER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "Parameter.h"
using namespace std;
class Header {
public:
    Header(){}
    vector<string> Attributes;
    pair<int, int> pair1;
    void setHeader (vector<Parameter> parameters) {
        Attributes.clear();
        for (unsigned int i = 0; i < parameters.size(); i++) {
            Attributes.push_back(parameters.at(i).toString());
        }
    };
    void setHeaderByStrings (vector<string> variables) {
        for (unsigned int i = 0; i < variables.size(); i++) {
            Attributes.push_back(variables.at(i));
        }
    }
    unsigned int getSize(){
        return Attributes.size();
    }
    vector<string> getVector(){
        return Attributes;
    }
    void addAttribute(string s) {
        Attributes.push_back(s);
    }
};


#endif //BRANDNEWPROJECT1_HEADER_H
