#ifndef PARSER_H
#define PARSER_H

#include "lexer/lexer.h"
#include <memory>

// Define the AST nodes
struct ASTNode {
    virtual ~ASTNode() = default;
};

struct NumberNode : ASTNode {
    double value;
    explicit NumberNode(double value);
};

struct BinaryOpNode : ASTNode {
    char op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
    BinaryOpNode(char op, std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right);
};

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::shared_ptr<ASTNode> parse();

private:
    std::shared_ptr<ASTNode> expression();
    std::shared_ptr<ASTNode> term();
    std::shared_ptr<ASTNode> factor();
    bool match(TokenType type) const;
    const Token& current() const;
    void advance();

    std::vector<Token> tokens;
    size_t pos;
};

#endif // PARSER_H
