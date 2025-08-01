#include <string>
#include <iostream>

int main() {
    // Creates a string with the value "HI THIS IS BRAIN"
    std::string brain_str = "HI THIS IS BRAIN";

    // Creates a pointer to the string
    std::string* stringPTR = &brain_str;

    // Creates a reference to the string
    std::string& stringREF = brain_str;
   
    // Displays the memory addresses
    std::cout << "Memory address of the brain string variable: " << &brain_str << std::endl;
    std::cout << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
   
    // Displays the values
    std::cout << "Value of the string variable: " << brain_str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
