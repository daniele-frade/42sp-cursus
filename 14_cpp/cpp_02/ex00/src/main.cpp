#include "Fixed.hpp"

int main(void) {
    Fixed a;           // Calls default constructor
    Fixed b(a);        // Calls copy constructor
    Fixed c;           // Calls default constructor
    c = b;             // Calls copy assignment operator

    std::cout << a.getRawBits() << std::endl;  // Calls getRawBits
    std::cout << b.getRawBits() << std::endl;  // Calls getRawBits
    std::cout << c.getRawBits() << std::endl;  // Calls getRawBits

    return 0;
}