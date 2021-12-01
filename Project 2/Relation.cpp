//
// Created by Daniel Steffen on 11/3/21.
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
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
    string newElement;
    vector<string> newElementVector;
    string s;
    newRelation.setName(name);
    for (Tuple t : tupleSet) {
        Tuple newTuple;
        for (unsigned int i =0; i < positions.size(); i++) {
            vector <string> testV = t.getVector();
            newElement = t.getVector().at(positions.at(i));
            newElementVector.push_back(newElement); //for input30 this should only be a, a, b for the first one.
        }
        newTuple.setTuple(newElementVector); //now i have a vector of all the values that I want in my new tuple (should only be in the specific columns specified by positions)
        newElementVector.clear();
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
Relation Relation::Join(Relation relation1) {
    pairVector.clear();
    Relation newRelation;
    newRelation.setName(name);
    newRelation.setHeader(combineHeaders(relation1));
    for (Tuple t : tupleSet) {
        for (Tuple t2 : relation1.getTupleSet())
        if (isJoinable(t,t2 )){
            Tuple newTuple;
            newTuple = combineTuples(t,t2);
            newRelation.addTuple(newTuple);
        }
    }
    return newRelation;
}

Header Relation::combineHeaders(Relation relation1) {
    Header newHeader = header;
    unsigned int number = 0;
    for (unsigned int i = 0; i < relation1.getHeader().getSize(); i++) {
        bool addable = true;
        number = i;
        for (unsigned int j = 0; j < header.getSize(); j++) {
            if (relation1.getHeader().getVector().at(i) == header.getVector().at(j)) {
                addable = false;
                pair1.first = j; // indexes where there are two of the same variables.
                pair1.second = i;
                pairVector.push_back(pair1);
            }
        }
        if (addable) {
            newHeader.addAttribute(relation1.getHeader().getVector().at(number));
        }
    }
    return newHeader;
    //for loop on relation1
    // for loop on header
    //}
    // if (check if its addable) {
    // push back onto new header}
}

bool Relation::isJoinable(Tuple tuple1, Tuple tuple2) {
    for (unsigned int i =0; i < pairVector.size(); i++) { //loop through vector of pairs
        if(tuple1.getVector().at(pairVector.at(i).first) != tuple2.getVector().at(pairVector.at(i).second)) { //loop through the
                return false;
            }
    }
    return true;
}

Tuple Relation::combineTuples(Tuple tuple1, Tuple tuple2) {
    Tuple newTuple = tuple1;
    bool isAddable;
    for (unsigned int i =0; i < tuple2.getVector().size(); i++){
        isAddable = true;
        for (unsigned int j =0; j < pairVector.size(); j++) {
            if (i == pairVector.at(j).second) {
                isAddable = false;
                break;
            }
        }
        if (isAddable) {
            string testString = tuple2.getVector().at(i);
            newTuple.addtoTuple(tuple2.getVector().at(i));
        }
    }
    return newTuple;
}

bool Relation::Unite(Relation relation2) {
    for (Tuple t : relation2.getTupleSet()){
        if (tupleSet.insert(t).second) {
            //cout << "successfully added this tuple to the database " << endl;
            for (unsigned int i = 0; i < t.getVector().size(); i++) {
                cout <<  "  " << header.getVector().at(i) << "=" << t.getVector().at(i);
                if (i < t.getVector().size()-1) {
                    cout << ", ";
                }
                else {
                    cout << endl;
                }

            }
            Added = true;
        }
        else {
            Added = false;
        }
    }
    return Added;
}
