#ifndef TOKEN_H
#define TOKEN_H
#include <string>

using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    OEF,
    UNDEFINED
};

class Token
{
private:
// TODO: add member variables for information needed by Token
    TokenType type;
    string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);
    string TokenTypeToString(TokenType type);
    void BecomeString(TokenType type, std::string description, int line);
    TokenType GetTokenType() {
        return type;
    }

    string GetString() {
        return description;
    }

    int GetLine() {
        return line;
    }

// TODO: add other needed methods


};

#endif // TOKEN_H
