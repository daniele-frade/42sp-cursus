#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>   // For std::numeric_limits
# include <cmath>    // For std::isnan, std::isinf
# include <iomanip>  // For std::fixed, std::setprecision
# include <cstdlib>  // For std::strtod, std::strtof, std::strtol
# include <cerrno>   // For errno

// ScalarConverter class: Non-instantiable, static method for type conversion.
class ScalarConverter {
private:
    // OCF: Prevent instantiation and copying.
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    // Main static method to convert and display scalar types.
    static void convert(const std::string& literal);
};

#endif