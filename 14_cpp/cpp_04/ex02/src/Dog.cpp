#include "Dog.hpp"

// Constructor
Dog::Dog() {
    type = "Dog";
    brainPointer = new Brain();
    std::cout << "Dog created" << std::endl;
}

// Destructor
Dog::~Dog() {
    delete brainPointer;
    std::cout << "Dog destroyed" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copied!" << std::endl;
    brainPointer = new Brain(*other.brainPointer);
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *this->brainPointer = *other.brainPointer;
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

// Override makeSound method
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brainPointer;
}
