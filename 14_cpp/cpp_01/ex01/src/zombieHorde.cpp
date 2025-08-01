#include "Zombie.hpp"

// Create a horde of N zombies, all with the same name
Zombie* zombieHorde(int N, std::string name) {
    
    // Allocate an array of N zombies
    Zombie* horde = new Zombie[N];

    if (N <= 0) {
        return NULL;
    }
    
    // Sets the name for each zombie in the horde
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    // Pointer to the first zombie in the horde
    return horde;
}