//
// Created by Daniel Steffen on 9/16/21.
//

#ifndef PROJECT1_STARTER_CODE_NOTCLOSEDSTRING_H
#define PROJECT1_STARTER_CODE_NOTCLOSEDSTRING_H

#include "Automaton.h"

class NotClosedStringAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);

public:
    NotClosedStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_NOTCLOSEDSTRING_H
