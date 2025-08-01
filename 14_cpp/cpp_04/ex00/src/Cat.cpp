#include "Cat.hpp"

// Constructor
Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

// Override makeSound method
void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}
