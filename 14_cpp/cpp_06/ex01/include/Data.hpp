#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

// A non-empty structure with data members.
struct Data {
private:
    int         _value;
    std::string _name;
    double      _decimal;

public:
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

    // Parameterized constructor
    Data(int val, const std::string& n, double dec);

    // Getters
    int                 getValue() const;
    const std::string&  getName() const;
    double              getDecimal() const;
};

#endif