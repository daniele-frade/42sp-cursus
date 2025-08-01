#include "ClapTrap.hpp"

// Default constructor implementation
ClapTrap::ClapTrap() : name("DefaultName"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called." << std::endl;
}

// Copy constructor implementation
ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

// Destructor implementation
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called." << std::endl;
}

// Copy assignment operator implementation
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

// Parameterized constructor implementation
ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap name constructor called with " << this->name << " value!" << std::endl;
}

// Attack implementation
void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        this->energyPoints--; // Reduce energy points by 1
    } else {
        std::cout << "ClapTrap " << name << " can't attack!" << std::endl;
    }
}

// Take damage implementation
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > 0) {
        this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and has " << hitPoints << " hit points left!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

// Repair implementation
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        this->hitPoints += amount; // Increase hit points by the repair amount
        this->energyPoints--; // Reduce energy points by 1
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " hit points and now has " << hitPoints << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't be repaired!" << std::endl;
    }
}
