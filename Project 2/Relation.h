#ifndef BRANDNEWPROJECT1_RELATION_H
#define BRANDNEWPROJECT1_RELATION_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#include "Header.h"
#include "Tuple.h"
class Relation {
private:
    string name;
    Header header;
    set<Tuple> tupleSet;
    vector<pair<unsigned int,unsigned int>> pairVector;
    pair<unsigned int, unsigned int> pair1;
    bool Added;
public:
    Header getHeader();
    set<Tuple> getTupleSet();
    Relation(){};
    Relation(string name, Header header, set<Tuple> tupleSet);
    void toString () {
        for (Tuple t : tupleSet) {
            for (unsigned int i = 0; i < t.values.size();i++) {
                if(i == t.values.size()-1) {
                    cout << "  " << header.Attributes.at(i) << "=" << t.values.at(i) << endl;
                }
                else {
                    cout << "  " << header.Attributes.at(i) << "=" << t.values.at(i) << ", ";
                }
            }
        }
    }
    void addTuple(Tuple addTuple) {
        tupleSet.insert(addTuple);
    }
    void setName(string newName) {
        name = newName;
    }
    void setHeader(Header addHeader) {
        header = addHeader;
    }
    string getName(){
        return name;
    }
    bool isEmpty () {
        if (tupleSet.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
    Relation selectConstant(int position , string constant);
    Relation selectSameValue(int position, int position2);
    Relation Project(vector<int> positions);
    void Rename(Header newHeader);

    // FOR PROJECT 4
    Header combineHeaders(Relation relation1);
    Relation Join(Relation relation1);
    bool isJoinable (Tuple tuple1, Tuple tuple2);
    Tuple combineTuples(Tuple tuple1, Tuple tuple2);
    bool Unite(Relation relation2);

};


#endif //BRANDNEWPROJECT1_RELATION_H
