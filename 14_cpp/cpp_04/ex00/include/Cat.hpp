#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

// Derived class Cat from Animal
class Cat : public Animal {
public:
    Cat(); // Constructor
    virtual ~Cat(); // Destructor
    Cat(const Cat& other); // Copy constructor
    Cat& operator=(const Cat& other); // Copy assignment operator

    // Override makeSound method
    void makeSound() const;
};

#endif