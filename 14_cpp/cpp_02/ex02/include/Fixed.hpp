#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors and Destructor
    Fixed(void);
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &that);
    ~Fixed(void);

    // Operator Overloads
    Fixed &operator=(const Fixed &that);

    // Comparison Operators
    bool operator>(const Fixed &that) const;
    bool operator<(const Fixed &that) const;
    bool operator>=(const Fixed &that) const;
    bool operator<=(const Fixed &that) const;
    bool operator==(const Fixed &that) const;
    bool operator!=(const Fixed &that) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed &that) const;
    Fixed operator-(const Fixed &that) const;
    Fixed operator*(const Fixed &that) const;
    Fixed operator/(const Fixed &that) const;

    // Increment/Decrement Operators
    Fixed &operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed &operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Conversion Methods
    float toFloat(void) const;
    int toInt(void) const;

    // Min/Max static methods
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Accessor methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

// Overload for << operator (insertion)
std::ostream &operator<<(std::ostream &o, const Fixed &that);

#endif