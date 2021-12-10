#ifndef BRANDNEWPROJECT1_GRAPH_H
#define BRANDNEWPROJECT1_GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "DatalogProgram.h"
using namespace std;
class Graph {
private:
    vector<int> postOrder;
    vector<Rules> rulesVector;
    set<int> dependents;
    set<int> reverseDependents;
    map<int, set<int>> graphMap;
    map<int, set<int>> reverseGraphMap;
    map<int, bool> visited;
    set<int> SCCs;
    vector<set<int>> SCCVector;
public:
    Graph(vector<Rules> fromInterpreterRules){
        rulesVector = fromInterpreterRules;
        for(unsigned int i = 0; i < rulesVector.size(); i++) {
            visited[i] = false;
        }
    }
    void Run();
    void GraphBuilder();
    void DFSReverseForest();
    void DFSFowardForest();
    void DFSNode(int p);
    void DFSNodeReverse(int p);
    vector<set<int>> getSCCVector(){
        return SCCVector;
    }



};


#endif //BRANDNEWPROJECT1_GRAPH_H
