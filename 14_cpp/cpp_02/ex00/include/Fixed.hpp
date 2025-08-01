#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed(); // Default constructor
    Fixed(Fixed const &other);// Copy constructor
    ~Fixed(); // Destructor

	Fixed& operator=(const Fixed &other); // Copy assignment operator
    
    int getRawBits(void) const; // Member function to get the raw value
    void setRawBits(int const raw); // Member function to set the raw value
};

#endif
