#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

// Wrong base class WrongAnimal
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal(); // Default constructor
    virtual ~WrongAnimal(); // Virtual destructor
    WrongAnimal(const WrongAnimal& other); // Copy constructor
    WrongAnimal& operator=(const WrongAnimal& other); // Copy assignment operator

    // Getter for type
    std::string getType() const;

    // Incorrectly defined makeSound method
    void makeSound() const;
};

#endif
