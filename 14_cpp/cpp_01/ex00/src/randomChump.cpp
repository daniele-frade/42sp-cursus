#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie tempZombie(name);
    tempZombie.announce();
}