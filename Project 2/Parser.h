//
// Created by Daniel Steffen on 9/29/21.
//
#include "Token.h"
#include "Lexer.h"
#include "Predicate.h"
#include "Rules.h"
#include "DatalogProgram.h"
#ifndef BRANDNEWPROJECT1_PARSER_H
#define BRANDNEWPROJECT1_PARSER_H


class Parser {
public:
    Parser(vector<Token*> newTokens);
    vector<Token*> newTokens;
    DatalogProgram datalogProgram;

    const DatalogProgram &getDatalogProgram() const;


    void parse();
    void parseFact();
    void parseSchemes();
    void parseRules();
    void parseQueries();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    Predicate headPredicate();
    Predicate predicate();
    void predicateList(vector<Predicate>& predvector);
    void parameterList(Predicate &predicate);
    void stringList(Predicate &predicate);
    void idList(Predicate &predicate);
    Parameter parameter(Predicate &predicate);

    unsigned int indexCounter = 0;

    void Match(TokenType type){
        if (newTokens.at(indexCounter)->GetTokenType() == type) {
            indexCounter++;
        }
        else {
            throw newTokens.at(indexCounter);
        }
    }
    //DatalogProgram parse();
    //Returning a DatalogProgram object will be helpful because you are essentially constructing your program as you parse your tokens. Once you are done parsing, you will have a finished Datalog program that has the lists of schemes, facts, rules and queries that will be needed in the next project


};


#endif //BRANDNEWPROJECT1_PARSER_H
