#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
using namespace std;
class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    int lineNumber;
    int maxRead;
    Automaton* maxAutomaton;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(string& input);
    void ToString();
    int GetSize() {
        return tokens.size();
    }

    vector<Token*> getTokens() {
        return tokens;
    }
    
    // TODO: add other public methods here

};

#endif // LEXER_H

