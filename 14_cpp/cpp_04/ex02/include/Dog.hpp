#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

// Derived class Dog from Animal
class Dog : public AAnimal {
private:
    Brain* brainPointer;
public:
    Dog(); // Constructor
    virtual ~Dog(); // Destructor
    Dog(const Dog& other); // Copy constructor
    Dog& operator=(const Dog& other); // Copy assignment operator

    void makeSound() const;
    Brain* getBrain() const;
};

#endif