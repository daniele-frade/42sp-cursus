#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(); // Default constructor
    FragTrap(const FragTrap& other); // Copy constructor
    ~FragTrap(); // Default destructor
    FragTrap& operator=(const FragTrap& other); // Copy assignment operator
    
    FragTrap(const std::string& name); // Parameterized constructor

    void    highFivesGuys(void); // Special function for FragTrap

};

#endif