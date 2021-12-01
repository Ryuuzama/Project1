#ifndef BRANDNEWPROJECT1_DATABASE_H
#define BRANDNEWPROJECT1_DATABASE_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "Relation.h"
using namespace std;
class Database {
public:

    map<string, Relation> relationMap;
    void addToMap(string name, Relation addRelation) {
        relationMap.insert(pair<string,Relation>(name,addRelation));
    }
    void maptoString() {
        for (pair<string, Relation>pairMap: relationMap) {
            cout << pairMap.first << endl;
            pairMap.second.toString();
            cout << endl;
        }
    }
    Relation& getFromMap(string s) {
        return relationMap.at(s);
    };

};


#endif //BRANDNEWPROJECT1_DATABASE_H
