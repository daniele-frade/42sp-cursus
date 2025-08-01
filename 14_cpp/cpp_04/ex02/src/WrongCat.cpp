#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied" << std::endl;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat assigned" << std::endl;
    return *this;
}

// Override makeSound method
void WrongCat::makeSound() const {
    std::cout << "WrongCat sound!" << std::endl;
}
