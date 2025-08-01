#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>
#include <limits>
#include <cerrno>

PmergeMe::PmergeMe(void) : numbers_vec(), numbers_deq(){}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->numbers_vec = other.numbers_vec;
        this->numbers_deq = other.numbers_deq;
    }
    return *this;
}

PmergeMe::~PmergeMe(void) {}

// parses command line arguments
void PmergeMe::parseInput(int ac, char **av) {

    if (ac <= 1)
        throw std::invalid_argument("missing argument");

    std::set<int> check_duplicates;
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]); 

        if (arg[0] == '-')
            throw std::invalid_argument("negative value not allowed");
        if (arg[0] == '+')
            throw std::invalid_argument("unsigned values only");
        if (arg.empty())
            throw std::invalid_argument("empty input");


        for (size_t j = 0; j < arg.size(); j++) {
            if (std::isspace(arg[j]))
                throw std::invalid_argument("each value must be a separate argument");
            if (!std::isdigit(arg[j]))
                throw std::invalid_argument("value is not a digit");
        }

        std::istringstream iss(arg);
        int num;
        iss >> num;

        if (check_duplicates.find(num) != check_duplicates.end())
            throw std::invalid_argument("duplicate values not allowed");
        check_duplicates.insert(num);

        // add the parsed number to both vector and deque
        numbers_vec.push_back(num);
        numbers_deq.push_back(num);
    }
}

// VECTOR AND DEQUE: orchestrates the sorting process for both containers
void PmergeMe::sort(void) {

    // display "Before" state
    std::cout << "\nBefore              : ";
    printContainer(numbers_vec);
    
    // time measurement for Deque
    std::clock_t start_deque = std::clock();
    sortDeque();
    std::clock_t end_deque = std::clock();

    // time measurement for Vector
    std::clock_t start_vector = std::clock();
    sortVector();
    std::clock_t end_vector = std::clock(); 

    // display "After" states
    std::cout << "\nAfter (std::vector) : ";
    printContainer(numbers_vec);
    std::cout << "\nAfter (std::deque)  : ";
    printContainer(numbers_deq);

    // display vector timing
    double duration_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;
    std::cout << "\nTime to process a range of " << numbers_vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(7) << duration_vector
              << " seconds" << std::endl;

    // display deque timing
    double duration_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << numbers_deq.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(7) << duration_deque
              << " seconds" << std::endl << std::endl;
}

// VECTOR: initiates the Merge-Insert Sort for the std::vector
void PmergeMe::sortVector(void) {
    if (numbers_vec.size() <= 1) {
        return;
    }
    numbers_vec = mergeInsertionVec(numbers_vec);
}

// DEQUE: initiates the Merge-Insert Sort for the std::deque
void PmergeMe::sortDeque(void) {
    if (numbers_deq.size() <= 1)
        return;
    numbers_deq = mergeInsertionDeq(numbers_deq);
}

// VECTOR: core recursive Merge-Insert Sort logic for std::vector
std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> vec) {

    if (vec.size() <= 1) {
        return vec;
    }
    
    std::vector<int> main_chain;
    std::vector<int> pend_chain;
    
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();

    // create pairs and sort them internally
    while (start + 1 < end) {
        if (*start < *(start + 1)) {
            pend_chain.push_back(*start);
            main_chain.push_back(*(start + 1));
        }
        else {
            pend_chain.push_back(*(start + 1));
            main_chain.push_back(*start);
        }
        start += 2;
    }
    if (start != end) {
        pend_chain.push_back(*start);
    }
    
    // recursively sort the 'main_chain' (the sequence of larger elements)
    main_chain = mergeInsertionVec(main_chain);

    // insert elements from 'pend_chain' into the sorted 'main_chain'
    std::vector<int> jacob_insertion_order = getInsertionOrderVec(pend_chain.size());
    
    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {
        
        if ((size_t)jacob_insertion_order[i] >= pend_chain.size())
            continue;

        int value_to_insert = pend_chain[jacob_insertion_order[i]];

        int low = 0;
        int high = main_chain.size() - 1;
        int insert_pos = 0;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (main_chain[middle] == value_to_insert) {
                insert_pos = middle;
                break;
            } else if (main_chain[middle] < value_to_insert) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
            insert_pos = low;
        }
        main_chain.insert(main_chain.begin() + insert_pos, value_to_insert);
    }
    
    // the sorted 'main_chain' is the result
    return main_chain;
}

// VECTOR: generates the insertion order sequence based on the Jacobsthal numbers
std::vector<int> PmergeMe::getInsertionOrderVec(size_t size) {

    std::vector<int> sequence;
    std::vector<bool> tracker(size, false);
    std::vector<int> jacobsthal = getJacobsthal<std::vector<int> >(size);

    size_t index = 0;
    while (index < jacobsthal.size()) {
        int num = jacobsthal[index] - 1;
        if (num >= 0 && (size_t)num < size && tracker[num] == false) {
             sequence.push_back(num);
             tracker[num] = true;
        }
        index++;
    }

    for (size_t i = 0; i < size; i++) {
        if (tracker[i] == false) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}


// DEQUE: core recursive Merge-Insert Sort logic for std::deque.
std::deque<int> PmergeMe::mergeInsertionDeq(std::deque<int> deq) {

    if (deq.size() <= 1) {
        return deq;
    }

    std::deque<int> main_chain;
    std::deque<int> pend_chain;

    std::deque<int>::iterator start = deq.begin();
    std::deque<int>::iterator end = deq.end();

    // create pairs and sort them internally
    while (start + 1 < end) {
        if (*start < *(start + 1)) {
            pend_chain.push_back(*start);
            main_chain.push_back(*(start + 1));
        }
        else {
            pend_chain.push_back(*(start + 1));
            main_chain.push_back(*start);
        }
        start += 2;
    }
    if (start != end) {
        pend_chain.push_back(*start);
    }
    
    // recursively sort the 'main_chain'
    main_chain = mergeInsertionDeq(main_chain);

    // insert elements from 'pend_chain' into the sorted 'main_chain'
    std::deque<int> jacob_insertion_order = getInsertionOrderDeq(pend_chain.size());
    
    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {
        if ((size_t)jacob_insertion_order[i] >= pend_chain.size())
            continue;

        int value_to_insert = pend_chain[jacob_insertion_order[i]];

        int low = 0;
        int high = main_chain.size() - 1;
        int insert_pos = 0;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (main_chain[middle] == value_to_insert) {
                insert_pos = middle;
                break;
            } else if (main_chain[middle] < value_to_insert) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
            insert_pos = low;
        }
        main_chain.insert(main_chain.begin() + insert_pos, value_to_insert);
    }
    
    // the sorted 'main_chain' is the result
    return main_chain;
}

// DEQUE: generates the insertion order sequence based on the Jacobsthal numbers
std::deque<int> PmergeMe::getInsertionOrderDeq(size_t size) {

    std::deque<int> sequence;
    std::deque<bool> tracker(size, false);
    std::deque<int> jacobsthal = getJacobsthal<std::deque<int> >(size);

    size_t index = 0;
    while (index < jacobsthal.size()) {
        int num = jacobsthal[index] - 1;
        if (num >= 0 && (size_t)num < size && tracker[num] == false) {
             sequence.push_back(num);
             tracker[num] = true;
        }
        index++;
    }

    for (size_t i = 0; i < size; i++) {
        if (tracker[i] == false) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}