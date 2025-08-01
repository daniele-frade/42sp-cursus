#include "Dog.hpp"

// Constructor
Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

// Override makeSound method
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}
