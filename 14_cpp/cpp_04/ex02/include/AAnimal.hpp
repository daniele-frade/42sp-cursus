#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

// Base class AAnimal
class AAnimal {
protected:
    std::string type;
public:
    AAnimal(); // Default constructor
    virtual ~AAnimal(); // Virtual destructor
    AAnimal(const AAnimal& other); // Copy constructor
    AAnimal& operator=(const AAnimal& other); // Copy assignment operator

    // Getter for type
    virtual std::string getType() const;

    // virtual method
    virtual void makeSound() const = 0;
};

#endif
