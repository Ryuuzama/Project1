//
// Created by Daniel Steffen on 9/16/21.
//

#include "CommentAutomaton.h"
void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if ((input[index] != '|')) {
            inputRead++;
            index++;
            S4(input);
        }
    else {
        Serr();
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (index == input.size()-1) {
        Serr();
        return;
    }
    if (input[index] == '\n') {
        newLines++;
    }
    if (input[index] != '|') {
            inputRead++;
            index++;
            S2(input);
        }
    if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        }
}

void CommentAutomaton::S3(const std::string& input) {
    if (index == input.size()-1) {
        Serr();
        return;
    }
    if (input[index] == '\n') {
        newLines++;
    }
    if (input.at(index) == '#') {
        inputRead++;
        return;
    }
    else if (input.at(index) == '|') {
        inputRead++;
        index++;
        S3(input);
    }

    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if (index == input.size()-1) {
        return;
    }
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] == '\n') {
        index++;
        return;
    }
}