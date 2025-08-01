#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// Wrong derived class WrongCat from WrongAnimal
class WrongCat : public WrongAnimal {
public:
    WrongCat(); // Constructor
    virtual ~WrongCat(); // Destructor
    WrongCat(const WrongCat& other); // Copy constructor
    WrongCat& operator=(const WrongCat& other); // Copy assignment operator

    // Override makeSound method
    void makeSound() const;
};

#endif

