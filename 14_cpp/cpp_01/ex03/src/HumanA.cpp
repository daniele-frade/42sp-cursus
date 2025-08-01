#include "HumanA.hpp"
#include <iostream>

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

// Destructor
HumanA::~HumanA() {};

// Prints the attack message
void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
