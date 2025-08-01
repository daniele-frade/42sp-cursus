#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// Definition of the Zombie class
class Zombie {
private:
    std::string name;  // Private attribute to store the zombie's name

public:
    Zombie();          // Constructor (default)
    ~Zombie();         // Destructor
    void setName(std::string name);  // Sets the name of the zombie
    void announce(void) const;       // Announces the zombie
};

// Function declaration to create a horde of zombies
Zombie* zombieHorde(int N, std::string name);

#endif
