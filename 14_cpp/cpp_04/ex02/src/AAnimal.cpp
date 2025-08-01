#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() : type("Unknown") {
    std::cout << "AAnimal created" << std::endl;
}

// Virtual destructor
AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copied" << std::endl;
}

// Copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "AAnimal assigned" << std::endl;
    return *this;
}

// Getter for type
std::string AAnimal::getType() const {
    return type;
}

// Implementation of makeSound() with generic sound
void AAnimal::makeSound() const {
    std::cout << "AAnimal generic sound!" << std::endl;
}
