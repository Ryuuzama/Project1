//
// Created by Daniel Steffen on 9/16/21.
//
#include <iostream>
#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] == '\n') {
        newLines++;
    }
    if (index == input.size()-1) {
        Serr();
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] != '\'') {
            inputRead++;
            index++;
            S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index]== '\'') {
        inputRead++;
        index++;
        S1(input);
    }

}

