#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
    // --- Comparison Test with std::list ---
    // The subject states: "If you run it a first time with your MutantStack, and a second time
    // replacing the MutantStack with, for example, a std::list, the two outputs should be the same." 
    std::cout << "\n--- Comparison Test with std::list ---" << std::endl;
    std::list<int> myList;
    myList.push_back(5); // push() for stack is like push_back() for list
    myList.push_back(17);

    std::cout << "Front element (list equivalent of top): " << myList.back() << std::endl;
    myList.pop_back(); // pop() for stack is like pop_back() for list
    std::cout << "Size after pop_back: " << myList.size() << std::endl;

    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::cout << "\nIterating through std::list:" << std::endl;
    std::list<int>::iterator list_it = myList.begin();
    std::list<int>::iterator list_ite = myList.end();

    while (list_it != list_ite) {
        std::cout << *list_it << std::endl;
        ++list_it;
    }

    // You can also compare with std::vector
    std::cout << "\n--- Comparison Test with std::vector ---" << std::endl;
    std::vector<int> myVector;
    myVector.push_back(5);
    myVector.push_back(17);

    std::cout << "Top element (vector equivalent of top): " << myVector.back() << std::endl;
    myVector.pop_back();
    std::cout << "Size after pop_back: " << myVector.size() << std::endl;

    myVector.push_back(3);
    myVector.push_back(5);
    myVector.push_back(737);
    myVector.push_back(0);

    std::cout << "\nIterating through std::vector:" << std::endl;
    std::vector<int>::iterator vec_it = myVector.begin();
    std::vector<int>::iterator vec_ite = myVector.end();

    while (vec_it != vec_ite) {
        std::cout << *vec_it << std::endl;
        ++vec_it;
    }


    // --- Test: Empty stack iteration ---
    std::cout << "\n--- Test: Empty MutantStack Iteration ---" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Iterating an empty stack (should print nothing):" << std::endl;
    for (MutantStack<int>::iterator it_empty = emptyStack.begin(); it_empty != emptyStack.end(); ++it_empty) {
        std::cout << *it_empty << std::endl;
    }

    // --- Test: Copy constructor and assignment operator ---
    std::cout << "\n--- Test: Copy Constructor and Assignment Operator ---" << std::endl;
    MutantStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);

    MutantStack<int> copy_constructed(original);
    std::cout << "Copy constructed stack (should be 10, 20, 30):" << std::endl;
    for (MutantStack<int>::iterator it_c = copy_constructed.begin(); it_c != copy_constructed.end(); ++it_c) {
        std::cout << *it_c << std::endl;
    }

    MutantStack<int> assigned;
    assigned.push(99);
    assigned = original;
    std::cout << "Assigned stack (should also be 10, 20, 30):" << std::endl;
    for (MutantStack<int>::iterator it_a = assigned.begin(); it_a != assigned.end(); ++it_a) {
        std::cout << *it_a << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

// // Main from subject:
// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }
// // Expected output from subject example, ordered from bottom to top:
// // 5 (after initial push, and 17, then pop)
// // 3
// // 5
// // 737
// // 0