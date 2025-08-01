#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

// Derived class Cat from Animal
class Cat : public AAnimal {
private:
    Brain* brainPointer;
public:
    Cat(); // Constructor
    virtual ~Cat(); // Destructor
    Cat(const Cat& other); // Copy constructor
    Cat& operator=(const Cat& other); // Copy assignment operator

    void makeSound() const;
    Brain* getBrain() const;
};

#endif