//
// Created by Daniel Steffen on 11/3/21.
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#include "Relation.h"

Relation::Relation (string name, Header header, set<Tuple> tupleSet) {
    name = "";
}

Relation Relation::selectConstant(int position, string constant){
    Relation newRelation;
    newRelation.setName(name);
    newRelation.setHeader(header);
    for (Tuple t : tupleSet) {
        if(t.getVector().at(position) == constant) {
            newRelation.addTuple(t);
        }
    }
    return newRelation;


}
Relation Relation::selectSameValue(int position, int position2){
    Relation newRelation;
    newRelation.setName(name);
    newRelation.setHeader(header);
    for (Tuple t : tupleSet) {
        if(t.getVector().at(position) == t.getVector().at(position2)) {
            newRelation.addTuple(t);
        }
    }
    return newRelation;
    //check if a tuple at this position = tuple at that position
}
Relation Relation::Project(vector<int> positions){
    Relation newRelation;
    Header newHeader;
    Parameter newParameter;
    vector<Parameter> newParameterVector;
    string s;
    newRelation.setName(name);
    for (Tuple t : tupleSet) {
        Tuple newTuple;
        for (unsigned int i =0; i < positions.size(); i++) {
            newParameter = t.getVector().at(positions.at(i));
            newParameterVector.push_back(newParameter); //for input30 this should only be a, a, b for the first one.
        }
        newTuple.setTuple(newParameterVector); //now i have a vector of all the values that I want in my new tuple (should only be in the specific columns specified by positions)
        newParameterVector.clear();
        newRelation.addTuple(newTuple);
    }
    for(unsigned int i =0; i < positions.size(); i++) {
        s = header.getVector().at(positions.at(i));
        newHeader.addAttribute(s);
    }
    newRelation.setHeader(newHeader);
    return newRelation;
    //loop through tuples, then loop through the vector of positions, make new tuple only with eh columns i want
}
void Relation::Rename(Header newHeader){
    header = newHeader;
}

Header Relation::getHeader() {
    return header;
}

set<Tuple> Relation::getTupleSet(){
    return tupleSet;
}
