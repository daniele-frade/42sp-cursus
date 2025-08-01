#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(Fixed const &other);
	Fixed(int const value);
  	Fixed(float const value);
    ~Fixed();

	Fixed& operator=(const Fixed &other);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
	
	int toInt(void) const;
  	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif