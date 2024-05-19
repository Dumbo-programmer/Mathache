#include "lexer/lexer.h"
#include <cassert>
#include <iostream>

void test_lexer() {
    std::string code = "3 + 4 * 2";
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();
    
    assert(tokens.size() == 7);
    assert(tokens[0].type == NUMBER && tokens[0].value == "3");
    assert(tokens[1].type == OP && tokens[1].value == "+");
    // Add more assertions as needed
}

int main() {
    test_lexer();
    std::cout << "All lexer tests passed!" << std::endl;
    return 0;
}
