#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Unknown") {
    std::cout << "Animal created" << std::endl;
}

// Virtual destructor
Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copied" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

// Getter for type
std::string Animal::getType() const {
    return type;
}

// Implementation of makeSound() with generic sound
void Animal::makeSound() const {
    std::cout << "Animal generic sound!" << std::endl;
}
