#include "HumanB.hpp"
#include <iostream>

// Constructor
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

// Destructor
HumanB::~HumanB() {};

// Sets the weapon
void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

// Prints the attack message
void HumanB::attack() {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}