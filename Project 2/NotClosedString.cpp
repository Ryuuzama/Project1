//
// Created by Daniel Steffen on 9/16/21.
//

#include "NotClosedString.h"
#include <iostream>

void NotClosedStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void NotClosedStringAutomaton::S1(const std::string& input) {
    if (input[index] == '\n') {
        newLines++;
    }
    if (index == input.size()-1) { //if it reaches end of file
        inputRead++;
        index++;
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

void NotClosedStringAutomaton::S2(const std::string& input) {
    if (input[index]== '\'') {
        inputRead++;
        index++;
        S1(input);
    }

}