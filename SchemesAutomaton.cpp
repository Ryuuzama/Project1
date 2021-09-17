//
// Created by Daniel Steffen on 9/16/21.
//

#include "SchemesAutomaton.h"

void SchemesAutomaton::S0(const std::string& input) {
    string SchemesString = "Schemes";
    for (int i = 0; i < 7; i++) {
        if (input[i] != SchemesString[i]) {
            Serr();
            return;
        }
    }
    inputRead = 7;
}