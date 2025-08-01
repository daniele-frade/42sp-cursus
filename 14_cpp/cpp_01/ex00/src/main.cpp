#include "Zombie.hpp"

int main() {
    std::cout << "\n" << std::endl;
    std::cout << "A HeapZombie object has been allocated on the heap." << std::endl;
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    std::cout << "=> Note that the destructor of the Heap Zombie was called only after explicitly invoking delete, as it remains in memory until manually deallocated." << std::endl;

    std::cout << "\n" << std::endl;
    
    std::cout << "A StackZombie object has been allocated on the stack." << std::endl;
    randomChump("StackZombie");
    std::cout << "=> Note that the destructor of the Stack Zombie was called automatically as soon as the randomChump(name) function scope ended." << std::endl;
    std::cout << "\n" << std::endl;
    return 0;
}
