#include "Bureaucrat.hpp"

int main() {
    std::cout << std::endl;
    std::cout << BOLD << YELLOW << "=== BUREAUCRAT CLASS TESTS ===" << RESET << std::endl << std::endl;

    // Test 1: Default constructor
    std::cout << YELLOW << "1. Testing default constructor with grade 150:" << RESET << std::endl;
    try {
        Bureaucrat defaultBureaucrat;
        std::cout << GREEN << "✓ Created: " << defaultBureaucrat << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Parameterized constructor with valid grade
    std::cout << YELLOW << "2. Testing parameterized constructor with valid grade (75):" << RESET << std::endl;
    try {
        Bureaucrat validBureaucrat("John", 75);
        std::cout << GREEN << "✓ Created: " << validBureaucrat << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Parameterized Constructor with invalid grade (too high)
    std::cout << YELLOW << "3. Testing parameterized constructor with grade too high (0):" << RESET << std::endl;
    try {
        Bureaucrat invalidHighBureaucrat("Mary", 0);
        std::cout << GREEN << "✗ Created: " << invalidHighBureaucrat << RESET << std::endl; // If you create, it's wrong
    } catch (const std::exception& e) {
        std::cout << RED << "✓ Exception caught correctly: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Parameterized constructor with grade too low (invalid)
    std::cout << YELLOW << "4. Testing parameterized constructor with grade too low (151):" << RESET << std::endl;
    try {
        Bureaucrat invalidHighBureaucrat("Mary", 151);
        std::cout << GREEN << "✗ Created: " << invalidHighBureaucrat << RESET << std::endl; // If you create, it's wrong
    } catch (const std::exception& e) {
        std::cout << RED << "✓ Exception caught correctly: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Valid grade increment
    std::cout << YELLOW << "5. Testing valid grade increment:" << RESET << std::endl;
    try {
        Bureaucrat testBureaucrat("Anna", 50);
        std::cout << "Before: " << testBureaucrat << std::endl;
        testBureaucrat.incrementGrade();
        std::cout << GREEN << "✓ After increment: " << testBureaucrat << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Valid grade decrement
    std::cout << YELLOW << "6. Testing valid grade decrement:" << RESET << std::endl;
    try {
        Bureaucrat testBureaucrat("Louise", 100);
        std::cout << "Before: " << testBureaucrat << std::endl;
        testBureaucrat.decrementGrade();
        std::cout << GREEN << "✓ After decrement: " << testBureaucrat << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Decrement that causes overflow (grade 150 -> 151)
    std::cout << YELLOW << "7. Testing decrement that causes overflow (grade 150):" << RESET << std::endl;
    try {
        Bureaucrat bottomBureaucrat("Robert", 150);
        std::cout << "Before: " << bottomBureaucrat << std::endl;
        bottomBureaucrat.decrementGrade(); // Should throw exception
        std::cout << GREEN << "✗ Should not reach here!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✓ Exception caught correctly: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << YELLOW << "=== ALL TESTS COMPLETED ===" << RESET << std::endl << std::endl;
    return 0;
}
