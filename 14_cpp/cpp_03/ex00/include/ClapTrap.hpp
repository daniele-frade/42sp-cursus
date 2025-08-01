#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string name; // Name of the ClapTrap
    unsigned int hitPoints; // Health points
    unsigned int energyPoints; // Energy points
    unsigned int attackDamage; // Damage dealt

public:
    ClapTrap(); // Default constructor
    ClapTrap(const ClapTrap& other); // Copy constructor
    ~ClapTrap(); // Default destructor
    ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
    
    ClapTrap(const std::string& name); // Parameterized constructor

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
