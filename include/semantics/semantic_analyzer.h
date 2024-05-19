#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "parser/parser.h"

class SemanticAnalyzer {
public:
    void analyze(const std::shared_ptr<ASTNode>& node);
};

#endif // SEMANTIC_ANALYZER_H
