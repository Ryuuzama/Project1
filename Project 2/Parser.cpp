//
// Created by Daniel Steffen on 9/29/21.
//
#include "Token.h"
#include "Parser.h"
#include "Predicate.h"
#include <vector>
#include <iostream>
#include "DatalogProgram.h"
using namespace std;


//When iterating through Tokens, if the Token has TokenType COMMENT, remove it

Parser::Parser(vector<Token*> ConTokens) {
    for (unsigned int i = 0; i < ConTokens.size(); i++) {
        if ((ConTokens.at(i)->GetTokenType()) != TokenType::COMMENT) {
            newTokens.push_back(ConTokens.at(i));
        }
    }


    /*for (unsigned int i = 0; i < newTokens.size(); i++) {
        newTokens.at(i)->BecomeString(newTokens.at(i)->GetTokenType(),newTokens.at(i)->GetString(),newTokens.at(i)->GetLine());
    }*/
    datalogProgram = DatalogProgram();
}

void Parser::parse(){
    //call the function for the start symbol

    try {
        Match(TokenType::SCHEMES);
        Match(TokenType::COLON);
        parseSchemes();
        schemeList();
        Match(TokenType::FACTS);
        Match(TokenType::COLON);
        factList();
        Match(TokenType::RULES);
        Match(TokenType::COLON);
        ruleList();
        Match(TokenType::QUERIES);
        Match(TokenType::COLON);
        parseQueries();
        queryList();
        Match(TokenType::OEF);

    }
    catch (Token* badToken)
    {
        /*cout << "Failure!" << endl;
        badToken->BecomeString(badToken->GetTokenType(),badToken->GetString(),badToken->GetLine());
        return;*/
    }
    //cout << datalogProgram.toString();
}

void Parser::parseFact() {
    Predicate fact;
    Match(TokenType::ID);
    fact.setName(newTokens.at(indexCounter-1)->GetString());
    Match(TokenType::LEFT_PAREN);
    Match(TokenType::STRING);
    Parameter paraFact(newTokens.at(indexCounter-1)->GetString());
    fact.addParameter(paraFact);
    stringList(fact);
    Match(TokenType::RIGHT_PAREN);
    Match(TokenType::PERIOD);
    datalogProgram.setFactsVector(fact);
}

void Parser::parseSchemes() {
    Predicate scheme;
    Match(TokenType::ID);
    scheme.setName(newTokens.at(indexCounter-1)->GetString());
    Match(TokenType::LEFT_PAREN);
    Match(TokenType::ID);
    Parameter paraScheme(newTokens.at(indexCounter-1)->GetString());
    scheme.addParameter(paraScheme);
    idList(scheme);
    Match(TokenType::RIGHT_PAREN);
    datalogProgram.setSchemesVector(scheme);

}

void Parser::parseRules() {
    Predicate firstPredicate;
    vector<Predicate> vectorRulePredicate;
    firstPredicate = headPredicate();
    Match(TokenType::COLON_DASH);
    vectorRulePredicate.push_back(predicate());
    //predicate();
    predicateList(vectorRulePredicate);
    Rules rules(firstPredicate, vectorRulePredicate);
    Match(TokenType::PERIOD);
    datalogProgram.setRulesVector(rules);
}

void Parser::parseQueries() {
    Predicate query;
    query = predicate();
    datalogProgram.setQueriesVector(query);
    Match(TokenType::Q_MARK);
}

void Parser::schemeList() {
    if (newTokens.at(indexCounter)->GetTokenType() != TokenType::FACTS) {
        parseSchemes();
        schemeList();
    }
}

void Parser::factList() {
    if (newTokens.at(indexCounter)->GetTokenType() != TokenType::RULES) {
        parseFact();
        factList();
    }
}

void Parser::ruleList() {
    if (newTokens.at(indexCounter)->GetTokenType() != TokenType::QUERIES) {
        parseRules();
        ruleList();
    }
}

void Parser::queryList() {
    if (newTokens.at(indexCounter)->GetTokenType() != TokenType::OEF) {
        parseQueries();
        queryList();
    }
}

Predicate Parser::headPredicate() {
    Predicate predicateObject;
    Match(TokenType::ID);
    predicateObject.setName(newTokens.at(indexCounter-1)->GetString());
    Match(TokenType::LEFT_PAREN);
    Match(TokenType::ID);
    Parameter paraHead(newTokens.at(indexCounter-1)->GetString());
    predicateObject.addParameter(paraHead);
    idList(predicateObject);
    Match(TokenType::RIGHT_PAREN);
    return predicateObject;
}

Predicate Parser::predicate() {
    Predicate predicateObject;
    Match(TokenType::ID);
    predicateObject.setName(newTokens.at(indexCounter-1)->GetString());
    Match(TokenType::LEFT_PAREN);
    parameter(predicateObject);
    parameterList(predicateObject);
    Match(TokenType::RIGHT_PAREN);
    return predicateObject;
}

void Parser::predicateList(vector<Predicate>& predicatevector) {
    if (newTokens.at(indexCounter)->GetTokenType() != (TokenType::COMMA) ) {
        return;
    }
    Match(TokenType::COMMA);
    predicatevector.push_back(predicate());
    predicateList(predicatevector);

}

void Parser::parameterList(Predicate &predicateObject) {
    if (newTokens.at(indexCounter)->GetTokenType() != (TokenType::COMMA) ) {
        return;
    }
    Match(TokenType::COMMA);
    parameter(predicateObject);
    parameterList(predicateObject);

}

void Parser::stringList(Predicate &fact) {
    if (newTokens.at(indexCounter)->GetTokenType() != (TokenType::COMMA) ) {
        return;
    }
    Match(TokenType::COMMA);
    Match(TokenType::STRING);
    Parameter paraFact(newTokens.at(indexCounter-1)->GetString());
    fact.addParameter(paraFact);
    stringList(fact);

}

void Parser::idList(Predicate &scheme) {
    if (newTokens.at(indexCounter)->GetTokenType() != (TokenType::COMMA) ) {
        return;
    }
    Match(TokenType::COMMA);
    Match(TokenType::ID);
    Parameter paraScheme(newTokens.at(indexCounter-1)->GetString());
    scheme.addParameter(paraScheme);
    idList(scheme);

}

Parameter Parser::parameter(Predicate &predicateObject) {
    Parameter para(newTokens.at(indexCounter)->GetString());
    if (newTokens.at(indexCounter)->GetTokenType() == TokenType::STRING) {
        Match(TokenType::STRING);
    }
    else {
        Match(TokenType::ID);
    }
    predicateObject.addParameter(para);
    return para;

}

const DatalogProgram &Parser::getDatalogProgram() const {
    return datalogProgram;
}
