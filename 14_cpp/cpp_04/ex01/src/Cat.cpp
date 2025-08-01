#include "Cat.hpp"

// Constructor
Cat::Cat() {
    type = "Cat";
    brainPointer = new Brain();
    std::cout << "Cat created" << std::endl;
}

// Destructor
Cat::~Cat() {
    delete brainPointer;
    std::cout << "Cat destroyed" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied!" << std::endl;
    brainPointer = new Brain(*other.brainPointer);
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *this->brainPointer = *other.brainPointer;
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

// Override makeSound method
void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brainPointer;
}
