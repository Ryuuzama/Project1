//
// Created by Daniel Steffen on 9/16/21.
//
#include "RulesAutomaton.h"
#include <iostream>
using namespace std;

void RulesAutomaton::S0(const std::string& input) {
    string RulesString = "Rules";
    for (int i = 0; i < 5; i++) {
        if (input[i] != RulesString[i]) {
            Serr();
            return;
        }
    }
    inputRead = 5;



    //cout << inputRead;
}
