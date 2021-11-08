//
// Created by Daniel Steffen on 9/16/21.
//

#include "IDAutomaton.h"
void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[index]) | isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    if (!isalpha(input[index]) | !isdigit(input[index])) {
        return;
    }
    else {
        Serr();
    }
}