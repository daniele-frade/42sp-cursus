#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

// Get raw bits
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}
