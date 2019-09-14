#include <iostream>
#include <sstream>
#include "calc.h"

int main(int argc, char *argv[]) {
    std::string line, tok;
    std::deque<double> state;

    while(std::cout << "> ") {
        // read whole line
        getline(std::cin, line);

        // iterate over words
        std::istringstream stream(line);
        while(stream >> tok) {
            Command *cmd;

            try {
                cmd = Command::parse(tok);
            } catch(std::invalid_argument e) {
                std::cout << "invalid argument" << std::endl;
                return EXIT_FAILURE;
            }

            cmd->execute(state);
            delete cmd;
        }

        for(double item : state) {
            std::cout << item;
            std::cout << " ";
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
