#include "Zombie.hpp"

int main() {
    std::string name = "HordeZombie";
    int N = 5;
    
    // Creates a horde of 5 zombies with the name "HordeZombie"
    Zombie* horde = zombieHorde(N, name);
    
    // Each zombie in the horde announces itself
    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        
        // Deletes the horde of zombies to free memory
        delete[] horde;
    }

    return 0;
}
