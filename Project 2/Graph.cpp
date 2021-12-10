//
// Created by Daniel Steffen on 12/9/21.
//

#include "Graph.h"
#include <algorithm>
void Graph::GraphBuilder() {
    //DEPENDENCY GRAPH
    for (unsigned int i = 0; i< rulesVector.size(); i++) {
        dependents.clear();
        for (unsigned int j = 0; j < rulesVector.at(i).getBody().size(); j++) {
            for (unsigned int m = 0; m < rulesVector.size(); m++) {
                if (rulesVector.at(i).getBody().at(j).getName() == rulesVector.at(m).getHead().getName()) {
                    dependents.insert(m);
                }
            }
        }
        graphMap.insert({ i,dependents}); //ADDING TO GRAPHMAP for ADJACENCY LIST
    }
    //REVERSE DEPENDENCY GRAPH
    for (unsigned int i = 0; i< rulesVector.size(); i++) {
        reverseDependents.clear();
        for (unsigned int m = 0; m < rulesVector.size(); m++) {
            for (unsigned int j = 0; j < rulesVector.at(m).getBody().size(); j++) {
                if (rulesVector.at(i).getHead().getName() == rulesVector.at(m).getBody().at(j).getName()) {
                    reverseDependents.insert(m);
                }
            }
        }
        reverseGraphMap.insert({ i,reverseDependents}); //ADDING TO GRAPHMAP for ADJACENCY LIST
    }
    //PRINTING MAP
    cout << "Dependency Graph" << endl;
    for (const auto& x : graphMap) {
        unsigned int index = 0;
        cout << "R" << x.first << ":";
        for (const auto& j : x.second) {
            cout << "R" << j;
            if (index != x.second.size()-1){
                cout << ",";
            }
            index++;
        }
        cout << endl;
    }
    cout << endl;

    //PRINTING REVERSE MAP for TESTING
    /*cout << "Reverse Dependency Graph" << endl;
    for (const auto& x : reverseGraphMap) {
        int index = 0;
        cout << "R" << x.first << ":";
        for (const auto& j : x.second) {
            cout << "R" << j;
            if (index != x.second.size()-1){
                cout << ",";
            }
            index++;
        }
        cout << endl;
    }
    cout << endl;*/
}

void Graph::DFSReverseForest() {
    for(unsigned int i = 0; i < rulesVector.size(); i++) {
        if (!visited.at(i)) {
            DFSNodeReverse(i);
        }
    }
}

void Graph::DFSFowardForest() {
    for(unsigned int i = 0; i < rulesVector.size(); i++) {
        visited.at(i) = false;
    }
    reverse(postOrder.begin(),postOrder.end());
    vector<int> postOrderCopy = postOrder;
    for (const auto &p : postOrderCopy) {
            if(!visited.at(p)) {
                DFSNode(p);
                SCCVector.push_back(SCCs);
                SCCs.clear();
            }
    }
}

void Graph::DFSNode(int p) {
    visited.at(p) = true;
    for (const auto & j : graphMap[p]) {
        if (!visited.at(j)) {
            DFSNode(j);
        }
    }
    SCCs.insert(p);
}

void Graph::DFSNodeReverse(int p) {
    visited.at(p) = true;
    for (const auto & j : reverseGraphMap[p]) {
        if (!visited.at(j)) {
            DFSNodeReverse(j);
        }
    }
    postOrder.push_back(p);
}





void Graph::Run() {
    postOrder.clear();
    graphMap.clear();
    reverseGraphMap.clear();
    GraphBuilder();
    DFSReverseForest();
    DFSFowardForest();
}