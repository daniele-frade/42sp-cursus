#include "Zombie.hpp"

// Constructor that initializes the zombie's name
Zombie::Zombie(std::string zombie_name)
{
    name = zombie_name;
}

// Destructor that prints the zombie's name when it is destroyed
Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

// Function that makes the zombie announce itself
void Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}