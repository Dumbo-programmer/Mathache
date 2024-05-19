#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType {
    NUMBER, ID, OP, LPAREN, RPAREN, LBRACE, RBRACE, COMMA, ASSIGN, FUNCTION, PLOT, DERIVATIVE, EOF_TYPE
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    std::vector<Token> tokenize();

private:
    Token number();
    Token identifier();

    std::string input;
    size_t pos;
    size_t length;
};

#endif // LEXER_H
