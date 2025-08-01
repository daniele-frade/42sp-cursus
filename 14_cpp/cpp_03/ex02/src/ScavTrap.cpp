#include "ScavTrap.hpp"

// Default constructor implementation
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

// Copy constructor implementation
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = other;
}

// Destructor implementation
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called." << std::endl;
}

// Copy assignment operator implementation
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assigment operator called." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Parameterized constructor implementation
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap parameterized constructor called." << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

// Attack implementation
void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        this->energyPoints--; // Reduce energy points by 1
    } else {
        std::cout << "ScavTrap " << name << " can't attack!" << std::endl;
    }
}

// Guard Gate implementation
void ScavTrap::guardGate() {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        std::cout << "ScavTrap " << name << " has now entered Gatekeeper mode."  << std::endl;
        this->energyPoints--; // Reduce energy points by 1
    } else {
        std::cout << "ScavTrap " << name << " is dead and cannot enter Gatekeeper mode." << std::endl;
    }
}