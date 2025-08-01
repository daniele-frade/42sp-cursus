#include "Zombie.hpp"

// Constructor
Zombie::Zombie() {
    std::cout << "zombie constructor called!" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

// Zombie name
void Zombie::setName(std::string zombie_name) {
    name = zombie_name;
}

// Zombie announce
void    Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}