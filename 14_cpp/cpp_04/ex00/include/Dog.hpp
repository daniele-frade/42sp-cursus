#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// Derived class Dog from Animal
class Dog : public Animal {
public:
    Dog(); // Constructor
    virtual ~Dog(); // Destructor
    Dog(const Dog& other); // Copy constructor
    Dog& operator=(const Dog& other); // Copy assignment operator

    // Override makeSound method
    void makeSound() const;
};

#endif