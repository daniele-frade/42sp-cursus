#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Implementation of the virtual destructor for Base
Base::~Base() {}

// It randomly instantiates A, B, or C and returns the instance as a Base pointer.
// srand(time(NULL)) MUST NOT be called here. It should be called once in main().
Base *generate(void) {
    int number = std::rand() % 3; // Generates 0, 1, or 2

    if (number == 0) {
        std::cout << "type A" << std::endl;
        return new A();
    } else if (number == 1) {
        std::cout << "type B" << std::endl;
        return new B();
    } else { // number == 2
        std::cout << "type C" << std::endl;
        return new C();
    }
}

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
// It checks if the dynamic_cast returns NULL.
void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// It prints the actual type of the object referenced by p.
// It uses a try-catch block to check if the cast failed.
void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p); // Attempt to cast to A&
        std::cout << "A" << std::endl;
        return; // Success, exit
    } catch (const std::exception &e) {
        // Cast to A& failed, try next
    }

    try {
        (void)dynamic_cast<B &>(p); // Attempt to cast to B&
        std::cout << "B" << std::endl;
        return; // Success, exit
    } catch (const std::exception &e) {
        // Cast to B& failed, try next
    }

    try {
        (void)dynamic_cast<C &>(p); // Attempt to cast to C&
        std::cout << "C" << std::endl;
        return; // Success, exit
    } catch (const std::exception &e) {
        // Cast to C& failed, type is unknown
    }
    std::cout << "Unknown type" << std::endl;
}