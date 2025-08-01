#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // --- Test with std::vector ---
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "\n--- Testing with std::vector ---" << std::endl;

    try {
        std::cout << "Searching for 30 in vector: ";
        std::vector<int>::iterator it_vec = easyfind(vec, 30);
        std::cout << "Found: " << *it_vec << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 100 in vector: ";
        std::vector<int>::iterator it_vec = easyfind(vec, 100);
        std::cout << "Found: " << *it_vec << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- Test with std::list ---
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    std::cout << "\n--- Testing with std::list ---" << std::endl;

    try {
        std::cout << "Searching for 15 in list: ";
        std::list<int>::iterator it_lst = easyfind(lst, 15);
        std::cout << "Found: " << *it_lst << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 55 in list: ";
        std::list<int>::iterator it_lst = easyfind(lst, 55);
        std::cout << "Found: " << *it_lst << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
