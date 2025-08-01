#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    // check args
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }
    // create an instance of the exchange, the database is loaded in the constructor
    BitcoinExchange btcExchange; 
    // process the input file provided as argument
    btcExchange.processInputFile(argv[1]);
    return 0;
}

// RPN tests:
// "5 1 2 + 4 * + 3 -" => 14
// "2 3 + 5 *" => 25
// "15 7 1 1 + - / 3 * 2 1 1 + + -" => 5