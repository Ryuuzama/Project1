
#ifndef BRANDNEWPROJECT1_PARAMETER_H
#define BRANDNEWPROJECT1_PARAMETER_H

#include <string>
using namespace std;

class Parameter {
public:
    Parameter(){};
    Parameter(string name);
    string name;
    string toString() {
        return name;
    }
};


#endif //BRANDNEWPROJECT1_PARAMETER_H
