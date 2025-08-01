#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) {
    _fixedPointValue = 0;
}

// Constructor from int
Fixed::Fixed(const int n) {
    _fixedPointValue = n << _fractionalBits; // Shift left to store as fixed-point
}

// Constructor from float
Fixed::Fixed(const float n) {
    _fixedPointValue = roundf(n * (1 << _fractionalBits)); // Convert float to fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed &that) {
    *this = that;
}

// Destructor
Fixed::~Fixed(void) {}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &that) {
    if (this != &that) {
        _fixedPointValue = that.getRawBits();
    }
    return *this;
}

// Comparison bigger than operator overload
bool Fixed::operator>(const Fixed &that) const {
    return _fixedPointValue > that._fixedPointValue;
}

// Comparison smaller than operator overload
bool Fixed::operator<(const Fixed &that) const {
    return _fixedPointValue < that.getRawBits();
}

// Comparison bigger or equal than operator overload
bool Fixed::operator>=(const Fixed &that) const {
    return _fixedPointValue >= that.getRawBits();
}

// Comparison smaller or equal than operator overload
bool Fixed::operator<=(const Fixed &that) const {
    return _fixedPointValue <= that.getRawBits();
}

// Comparison equal operator overload
bool Fixed::operator==(const Fixed &that) const {
    return _fixedPointValue == that.getRawBits();
}

// Comparison different operator overload
bool Fixed::operator!=(const Fixed &that) const {
    return _fixedPointValue != that.getRawBits();
}

// Arithmetic sum operator overload
Fixed Fixed::operator+(const Fixed &that) const {
    return Fixed(this->toFloat() + that.toFloat());
}

// Arithmetic subtraction operator overload
Fixed Fixed::operator-(const Fixed &that) const {
    return Fixed(this->toFloat() - that.toFloat());
}

// Arithmetic multiplication operator overload
Fixed Fixed::operator*(const Fixed &that) const {
    return Fixed(this->toFloat() * that.toFloat());
}

// Arithmetic division operator overload
Fixed Fixed::operator/(const Fixed &that) const {
    return Fixed(this->toFloat() / that.toFloat());
}

// Pre-increment operator overload
Fixed &Fixed::operator++() {
    _fixedPointValue++;
    return *this;
}

// Post-increment operator overload
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _fixedPointValue++;
    return temp;
}

// Pre-decrement operator overload
Fixed &Fixed::operator--() {
    _fixedPointValue--;
    return *this;
}

// Post-decrement operator overload
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _fixedPointValue--;
    return temp;
}

// Conversion to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Conversion to int
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Min funcion
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

// Min funcion const
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

// Max funcion
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

// Max funcion const
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Get raw bits (getter)
int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

// Set raw bits (setter)
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Overload for << operator
std::ostream &operator<<(std::ostream &out, const Fixed &that) {
    out << that.toFloat();
    return out;
}
