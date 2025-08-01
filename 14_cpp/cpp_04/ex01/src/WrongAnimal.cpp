#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created" << std::endl;
}

// Virtual destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copied" << std::endl;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "WrongAnimal assigned" << std::endl;
    return *this;
}

// Getter for type
std::string WrongAnimal::getType() const {
    return type;
}

// Incorrectly defined makeSound method
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound!" << std::endl;
}
