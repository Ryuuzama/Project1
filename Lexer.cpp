#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "QueriesAutomaton.h"
#include "RulesAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include"RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "NotClosedString.h"
#include "NotClosedComment.h"
#include <iostream>
using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new NotClosedStringAutomaton());
    automata.push_back(new NotClosedCommentAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {

    lineNumber = 1;

    while (input.size() > 0) {    // While there are more characters to tokenize

        // Here is the "Parallel" part of the algorithm, Each automaton runs with the same input,  me: Runs through all automata, most reject it. Sometimes two accept it, then it takes whatever is the longest inputRead
        int inputRead;
        maxRead = 0; //maxRead is number of characters in maxAutomaton
        maxAutomaton = automata.front(); // set maxAutomaton to first automaton in automata //maxAutomaton is automaton that had most characters


        // handling whitespace in between tokens
        while ((input.substr(0,1) == " ") || (input.substr(0,1) == "\n") || (input.substr(0,1) == "\t")) {

            if (input.substr(0,1) == "\n") {
                lineNumber++;
            }
            input.erase(0,1);
        }

        if (input.size() == 0) {
            break;
        }

        // Here is the "Max" part of the algorithm
        for (unsigned int i = 0; i < automata.size(); i++) {
            inputRead = automata.at(i)->Start(input);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }

        //input is now

        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }

        else {
            maxRead = 1;

            Token *newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
            tokens.push_back(newToken);
        }

        input = input.substr(maxRead);
    }


    Token *newToken = new Token(TokenType::OEF, "", lineNumber);
    tokens.push_back(newToken);

}



void Lexer::ToString() {
    for (unsigned int i = 0; i < tokens.size(); i++) {
        Token *newToken = tokens.at(i);
        newToken->Token::BecomeString(tokens.at(i)->GetTokenType(), tokens.at(i)->GetString(), tokens.at(i)->GetLine());
    }

}



