#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string type) : type(type) {}

// Destructor
Weapon::~Weapon() {};

// Returns the type of the weapon
std::string const &Weapon::getType() const {
    return type;
}

// Sets the type of the weapon
void Weapon::setType(std::string type) {
    this->type = type;
}
