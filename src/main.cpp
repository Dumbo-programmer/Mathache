#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "semantics/semantic_analyzer.h"
#include "interpreter/interpreter.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.math>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    if (filename.substr(filename.find_last_of(".") + 1) != "math") {
        std::cerr << "Error: File extension must be .math" << std::endl;
        return 1;
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();

    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    SemanticAnalyzer analyzer;
    analyzer.analyze(ast);

    Interpreter interpreter;
    interpreter.interpret(ast);

    return 0;
}
