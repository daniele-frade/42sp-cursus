#include "Data.hpp"

Data::Data() : _value(0), _name("default"), _decimal(0.0) {
    std::cout << "Data: Default constructor called" << std::endl;
}

Data::Data(const Data& other) :
    _value(other._value),
    _name(other._name),
    _decimal(other._decimal) {
    std::cout << "Data: Copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other) {
    std::cout << "Data: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
        this->_name = other._name;
        this->_decimal = other._decimal;
    }
    return *this;
}

Data::~Data() {
    std::cout << "Data: Destructor called" << std::endl;
}

Data::Data(int val, const std::string& n, double dec) :
    _value(val), _name(n), _decimal(dec) {
    std::cout << "Data: Parameterized constructor called" << std::endl;
}

// Getters
int Data::getValue() const {
    return _value;
}

const std::string& Data::getName() const {
    return _name;
}

double Data::getDecimal() const {
    return _decimal;
}