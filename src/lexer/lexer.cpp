#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& input) : input(input), pos(0), length(input.length()) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < length) {
        char current = input[pos];
        if (isdigit(current)) {
            tokens.push_back(number());
        } else if (isalpha(current)) {
            tokens.push_back(identifier());
        } else if (current == '+' || current == '-' || current == '*' || current == '/') {
            tokens.push_back({OP, std::string(1, current)});
            pos++;
        } else if (current == '(') {
            tokens.push_back({LPAREN, "("});
            pos++;
        } else if (current == ')') {
            tokens.push_back({RPAREN, ")"});
            pos++;
        } else if (current == '{') {
            tokens.push_back({LBRACE, "{"});
            pos++;
        } else if (current == '}') {
            tokens.push_back({RBRACE, "}"});
            pos++;
        } else if (current == ',') {
            tokens.push_back({COMMA, ","});
            pos++;
        } else if (current == '=') {
            tokens.push_back({ASSIGN, "="});
            pos++;
        } else if (isspace(current)) {
            pos++;
        } else {
            std::cerr << "Unexpected character: " << current << std::endl;
            pos++;
        }
    }
    tokens.push_back({EOF_TYPE, ""});
    return tokens;
}

Token Lexer::number() {
    size_t start = pos;
    while (pos < length && isdigit(input[pos])) pos++;
    return {NUMBER, input.substr(start, pos - start)};
}

Token Lexer::identifier() {
    size_t start = pos;
    while (pos < length && isalnum(input[pos])) pos++;
    std::string id = input.substr(start, pos - start);
    if (id == "function") return {FUNCTION, id};
    if (id == "plot") return {PLOT, id};
    if (id == "derivative") return {DERIVATIVE, id};
    return {ID, id};
}
