#include "Base.hpp"
#include <iostream>

int main() {
    
    // Seed the random number generator ONCE at the very beginning of the program.
    // This is crucial for truly different random numbers across multiple generate() calls.
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    std::cout << "--- Test 1 ---" << std::endl;
    std::cout << "Generating a random instance: ";
    Base* random_instance1 = generate();
    
    std::cout << "Identifying the type using a POINTER: ";
    identify(random_instance1);
    
    std::cout << "Identifying the type using a REFERENCE: ";
    identify(*random_instance1);
    
    std::cout << "Cleaning up memory.";
    delete random_instance1;
    std::cout << std::endl;

    std::cout << "\n--- Test 2 ---" << std::endl;
    std::cout << "Generating a new random instance: ";
    Base* random_instance2 = generate();
     
    std::cout << "Identifying the type using a POINTER: ";
    identify(random_instance2);
    
    std::cout << "Identifying the type using a REFERENCE: ";
    identify(*random_instance2);
    
    std::cout << "Cleaning up memory.";
    delete random_instance2;
    std::cout << std::endl;
    
    std::cout << "\n--- Test 3 ---" << std::endl;
    std::cout << "Generating a new random instance: ";
    Base* random_instance3 = generate();

    
    std::cout << "Identifying the type using a POINTER: ";
    identify(random_instance3);

    
    std::cout << "Identifying the type using a REFERENCE: ";
    identify(*random_instance3);

    
    std::cout << "Cleaning up memory.";
    delete random_instance3;
    std::cout << std::endl;

    return 0;
}