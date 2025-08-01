#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <ctime>
#include <iomanip>

class PmergeMe {

    private:
        // containers
        std::vector<int>    numbers_vec;
        std::deque<int>     numbers_deq;
        
        // initiates the Merge-Insert Sort for the std::vector
        void sortVector(void);
        // core recursive Merge-Insert Sort logic
        std::vector<int> mergeInsertionVec(std::vector<int> vec);
        // generates the insertion order sequence
        std::vector<int> getInsertionOrderVec(size_t size);
        
        // initiates the Merge-Insert Sort for the std::deque
        void sortDeque(void);
        // core recursive Merge-Insert Sort logic
        std::deque<int> mergeInsertionDeq(std::deque<int> deq);
        // generates the insertion order sequence
        std::deque<int> getInsertionOrderDeq(size_t size);

        // template method to print the elements of any container
        template <typename T_container>
        void printContainer(T_container& container) {
            typename T_container::iterator it = container.begin();
            while (it != container.end()) {
                std::cout << *it << " ";
                it++;
            }
            std::cout << std::endl;
        }

        // template method to generate a Jacobsthal-like sequence
        template <typename T_container>
        T_container getJacobsthal(size_t size) {
            T_container jacobsthal;
            size_t index = 0;
            int element = 1;

            jacobsthal.push_back(element); 
            jacobsthal.push_back(element);

            while (element <= (int)size) {
                element = element + (jacobsthal[index] * 2); 
                jacobsthal.push_back(element);
                index++;
            }
            jacobsthal.erase(jacobsthal.begin());
            jacobsthal.pop_back();
            return jacobsthal;
        }

    public:
        // OCF
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe(void);
        PmergeMe& operator=(const PmergeMe &other);

        // parses command line arguments
        void parseInput(int ac, char **av);
        // orchestrates the sorting process for both containers
        void sort(void);

};

#endif