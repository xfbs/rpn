#include <iostream>
#include <sstream>
#include "parse.h"

int main(int argc, char *argv[]) {
    std::string line, tok;

    while(std::cout << "> ") {
        std::deque<std::string> tokens, rpn;

        // read whole line
        getline(std::cin, line);

        // iterate over words
        std::istringstream stream(line);
        while(stream >> tok) {
            tokens.push_back(tok);
        }

        Node *ast = Node::parse(tokens);
        ast->to_rpn(rpn);

        for(std::string str : rpn) {
            std::cout << str << " ";
        }

        delete ast;

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
