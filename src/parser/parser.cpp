#include "parser.h"
#include <stdexcept>

NumberNode::NumberNode(double value) : value(value) {}

BinaryOpNode::BinaryOpNode(char op, std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right)
    : op(op), left(left), right(right) {}

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

std::shared_ptr<ASTNode> Parser::parse() {
    return expression();
}

std::shared_ptr<ASTNode> Parser::expression() {
    auto left = term();
    while (match(OP) && (current().value == "+" || current().value == "-")) {
        char op = current().value[0];
        advance();
        auto right = term();
        left = std::make_shared<BinaryOpNode>(op, left, right);
    }
    return left;
}

std::shared_ptr<ASTNode> Parser::term() {
    auto left = factor();
    while (match(OP) && (current().value == "*" || current().value == "/")) {
        char op = current().value[0];
        advance();
        auto right = factor();
        left = std::make_shared<BinaryOpNode>(op, left, right);
    }
    return left;
}

std::shared_ptr<ASTNode> Parser::factor() {
    if (match(NUMBER)) {
        double value = std::stod(current().value);
        advance();
        return std::make_shared<NumberNode>(value);
    } else if (match(LPAREN)) {
        advance();
        auto node = expression();
        if (!match(RPAREN)) {
            throw std::runtime_error("Expected ')'");
        }
        advance();
        return node;
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

bool Parser::match(TokenType type) const {
    return pos < tokens.size() && tokens[pos].type == type;
}

const Token& Parser::current() const {
    return tokens[pos];
}

void Parser::advance() {
    if (pos < tokens.size()) pos++;
}
