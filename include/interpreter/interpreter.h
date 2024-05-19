#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser/parser.h"

class Interpreter {
public:
    double interpret(const std::shared_ptr<ASTNode>& node);
};

#endif // INTERPRETER_H
