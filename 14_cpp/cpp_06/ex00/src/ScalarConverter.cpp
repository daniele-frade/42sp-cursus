#include "ScalarConverter.hpp"

// OCF implementations: empty as class is not meant to be instantiated.
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// Helper: Checks if string is a char literal (e.g., "'c'").
static bool isCharLiteral(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

// Helper: Checks if string is a pseudo-literal (e.g., "nan", "+inf").
static bool isPseudoLiteral(const std::string& literal) {
    return literal == "nan" || literal == "nanf" ||
           literal == "+inf" || literal == "+inff" ||
           literal == "-inf" || literal == "-inff";
}

// Helper: Prints output for pseudo-literais.
static void printPseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// Main static method to convert and display scalar types.
void ScalarConverter::convert(const std::string& literal) {
    // 1. Handle pseudo-literals immediately.
    if (isPseudoLiteral(literal)) {
        printPseudoLiteral(literal);
        return;
    }

    double d_value;
    char *endptr;
    errno = 0; // Clear errno for error checking with strtod.

    // 2. Attempt conversion to double using strtod.
    // strtod converts the string pointed to by literal.c_str() to a double.
    // 'endptr' will point to the first character not part of the number.
    d_value = std::strtod(literal.c_str(), &endptr);

    // 3. Robust Error Checking for strtod.
    bool conversion_failed = false;

    // Check if no characters were converted (e.g., empty string, "abc").
    // If endptr points to the beginning of the string, no valid number was found.
    if (endptr == literal.c_str()) {
        conversion_failed = true;
    }
    // Check for overflow/underflow (ERANGE indicates value out of range for double).
    else if (errno == ERANGE) {
        conversion_failed = true;
    }
    // Check for trailing unconverted characters, unless it's a valid float suffix ('f' or 'F').
    else if (*endptr != '\0') { // If endptr is not null terminator, there are unconverted characters
        // Check if the unconverted part is exactly 'f' or 'F' and nothing else.
        std::string remaining(endptr);
        if (!(remaining.length() == 1 && (remaining[0] == 'f' || remaining[0] == 'F'))) {
            conversion_failed = true;
        }
    }

    // Handle conversion failure or identify char literal.
    if (conversion_failed) {
        // If numeric conversion failed, check if it's a char literal (e.g., "'c'").
        if (isCharLiteral(literal)) {
            d_value = static_cast<double>(literal[1]); // Use ASCII value for char.
        } else {
            // If neither a number nor a char literal, it's impossible.
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    // 4. Convert and display to char, handling displayability and limits.
    std::cout << "char: ";
    char c_value = static_cast<char>(d_value);
    // Check if d_value is out of char range, or is NaN/Inf.
    if (d_value < std::numeric_limits<char>::min() || d_value > std::numeric_limits<char>::max() ||
        std::isnan(d_value) || std::isinf(d_value)) {
        std::cout << "impossible" << std::endl;
    }
    // Check if char is non-displayable (ASCII control characters).
    else if (c_value < 32 || c_value > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << c_value << "'" << std::endl;
    }

    // 5. Convert and display to int, handling limits and special values.
    std::cout << "int: ";
    // Check if d_value is out of int range, or is NaN/Inf.
    if (d_value < std::numeric_limits<int>::min() || d_value > std::numeric_limits<int>::max() ||
        std::isnan(d_value) || std::isinf(d_value)) {
        std::cout << "impossible" << std::endl;
    } else {
        int i_value = static_cast<int>(d_value);
        std::cout << i_value << std::endl;
    }

    // 6. Convert and display to float, handling special values and precision.
    std::cout << "float: ";
    // Check for float overflow/underflow (conversion to float would be 'inf' or '0.0' for extremes).
    if ((d_value > 0 && d_value > std::numeric_limits<float>::max()) ||
        (d_value < 0 && d_value < -std::numeric_limits<float>::max())) { // Float overflow/underflow check
        std::cout << "impossible" << std::endl;
    } else if (std::isinf(d_value) && d_value > 0) { // Positive infinity
        std::cout << "+inff" << std::endl;
    } else if (std::isinf(d_value) && d_value < 0) { // Negative infinity
        std::cout << "-inff" << std::endl;
    } else if (std::isnan(d_value)) { // Not a Number
        std::cout << "nanf" << std::endl;
    } else {
        float f_value = static_cast<float>(d_value);
        std::cout << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
    }

    // 7. Convert and display to double, handling special values and precision.
    // d_value is already double, so no specific numerical limit checks needed for double itself,
    // only for its special representations.
    std::cout << "double: ";
    if (std::isinf(d_value) && d_value > 0) {
        std::cout << "+inf" << std::endl;
    } else if (std::isinf(d_value) && d_value < 0) {
        std::cout << "-inf" << std::endl;
    } else if (std::isnan(d_value)) {
        std::cout << "nan" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << d_value << std::endl;
    }
}