#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./RPN \"<RPN expression>\"" << std::endl;
        return EXIT_FAILURE;
    }
    try {
        int result = RPN::evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
