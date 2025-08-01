#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>

int main(int ac, char **av) {
    try {
        // instantiate PmergeMe with initialized containers
        PmergeMe sorter; 

        // parse and validate the args
        sorter.parseInput(ac, av); 

        // execute the sorting process for both containers and display results/timings
        sorter.sort();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

// Generate random input: 
// ./PmergeMe $(shuf -i 1-1000 -n 20)
// ./PmergeMe $(shuf -i 1-1000000 -n 3000)
