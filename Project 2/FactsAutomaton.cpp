//
// Created by Daniel Steffen on 9/16/21.
//

#include "FactsAutomaton.h"
#include <iostream>
using namespace std;

void FactsAutomaton::S0(const std::string& input) {
    string QueriesString = "Facts";
    for (int i = 0; i < 5; i++) {
        if (input[i] != QueriesString[i]) {
            Serr();
            return;
        }
    }
    inputRead = 5;
}