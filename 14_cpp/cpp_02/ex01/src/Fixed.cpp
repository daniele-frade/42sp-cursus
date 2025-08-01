#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

// Integer Constructor: 
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intValue << _fractionalBits;
}

// Float Constructor:
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
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
    return _fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Set to float:
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Set to int:
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Overload for << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}