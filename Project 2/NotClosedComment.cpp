//
// Created by Daniel Steffen on 9/17/21.
//

#include "NotClosedComment.h"
#include <istream>

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
    else if ((input[index] != '|')) {
        Serr();
    }
}

void NotClosedCommentAutomaton::S2(const std::string& input) {
    if (index == input.size()-1) {
        inputRead++;
        if (input[index] == '\n') {
            newLines++;
        }
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

void NotClosedCommentAutomaton::S3(const std::string& input) {
    if (index == input.size()-1) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        return;
    }
    if (input[index] == '\n') {
        newLines++;
    }
    if (input.at(index) == '#') {
        inputRead++;
        Serr();
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