#include "interpreter.h"
#include "standard_library/standard_library.h"
#include <stdexcept>

double Interpreter::interpret(const std::shared_ptr<ASTNode>& node) {
    if (auto numNode = std::dynamic_pointer_cast<NumberNode>(node)) {
        return numNode->value;
    } else if (auto binOpNode = std::dynamic_pointer_cast<BinaryOpNode>(node)) {
        double left = interpret(binOpNode->left);
        double right = interpret(binOpNode->right);
        switch (binOpNode->op) {
            case '+': return StandardLibrary::add(left, right);
            case '*': return StandardLibrary::multiply(left, right);
            // Handle other operations...
        }
    }
    throw std::runtime_error("Unknown AST node");
}
