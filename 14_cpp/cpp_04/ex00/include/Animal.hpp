#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// Base class Animal
class Animal {
protected:
    std::string type;
public:
    Animal(); // Default constructor
    virtual ~Animal(); // Virtual destructor
    Animal(const Animal& other); // Copy constructor
    Animal& operator=(const Animal& other); // Copy assignment operator

    // Getter for type
    virtual std::string getType() const;

    // virtual method
    virtual void makeSound() const;
};

#endif
