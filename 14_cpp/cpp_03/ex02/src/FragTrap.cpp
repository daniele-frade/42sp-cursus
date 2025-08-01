#include "FragTrap.hpp"

// Default constructor implementation
FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called." << std::endl;
}

// Copy constructor implementation
FragTrap::FragTrap(const FragTrap& other) : ClapTrap() {
    *this = other;
    std::cout << "FragTrap copy constructor called." << std::endl;
}

// Destructor implementation
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called." << std::endl;
}

// Copy assignment operator implementation
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other)
    {
        this->hitPoints = other.hitPoints;   // Override the default hit points for ScavTrap
        this->energyPoints = other.energyPoints; // Override the default energy points for ScavTrap
        this->attackDamage = other.attackDamage; // Override the default attack damage for ScavTrap
    }
    std::cout << "FragTrap parameterized constructor called." << std::endl;
    return *this;
}

// Parameterized constructor implementation
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->name = name;
    this->hitPoints = 100;   // Override the default hit points for ScavTrap
    this->energyPoints = 50; // Override the default energy points for ScavTrap
    this->attackDamage = 20; // Override the default attack damage for ScavTrap
    std::cout << "FragTrap parameterized constructor called." << std::endl;
}

// High Five implementation
void FragTrap::highFivesGuys(void) {
    std::cout << "High five guys!" << std::endl;
}