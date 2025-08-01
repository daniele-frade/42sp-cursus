#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(); // Default constructor
    ScavTrap(const ScavTrap& other); // Copy constructor
    ~ScavTrap(); // Default destructor
    ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator
    
    ScavTrap(const std::string& name); // Parameterized constructor

    void attack(const std::string& target); // Redefine attack
    void guardGate(); // Special function for ScavTrap
};

#endif

