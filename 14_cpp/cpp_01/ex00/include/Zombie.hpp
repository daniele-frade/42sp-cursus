#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string zombie_name);  // Construtor
    ~Zombie();                        // Destrutor
    void announce(void) const;
};

// Create a zombie on the heap
Zombie  *newZombie(std::string name);

// Create a zombie on the stack
void    randomChump(std::string name);

#endif
