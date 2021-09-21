//
// Created by Daniel Steffen on 9/17/21.
//

#include "NotClosedComment.h"

void NotClosedCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void NotClosedCommentAutomaton::S1(const std::string& input) {

    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    if ((input[index] != '|')) {
        inputRead++;
        index++;
        return;
    }
}

void NotClosedCommentAutomaton::S2(const std::string& input) {
    if (input[index] == '\n') {
        newLines++;
    }
    if (index == input.size()-1) {
        inputRead++;
        return;
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

void NotClosedCommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        return;
    }
}

void NotClosedCommentAutomaton::S4(const std::string& input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    if (input[index] == '\n') {
        index++;
        return;
    }
}