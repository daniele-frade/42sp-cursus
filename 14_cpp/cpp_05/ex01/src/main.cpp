#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::cout << std::endl;
    std::cout << BOLD << YELLOW << "=== FORM CLASSES TESTS ===" << RESET << std::endl << std::endl;

    // 1. Attempting to create an impossible form
    std::cout << YELLOW << "1. Creating a AForm with a GradeTooHigh requirement (grade 0)." << RESET << std::endl;
    try {
        AForm formF001("AForm F-001", 0, 1);
        std::cout << RED << "✗ AForm created: " << formF001 << RESET << std::endl;
    } catch(const std::exception &e) {
        std::cerr << RED << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // 2. The Junior Bureaucrat's First Success
    std::cout << YELLOW << "2. The Junior Bureaucrat's First Success: Alice attempts to sign a standard request." << RESET << std::endl;
    try {
        Bureaucrat alice("Alice Green", 75);
        AForm formF002("AForm F-002", 80, 90);
        alice.signForm(formF002);
    } catch (const std::exception &e) {
        std::cerr << RED << "✓ Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // 3. The Intern's Failure
    std::cout << YELLOW << "3. The Intern's Failure: Bob tries to sign a critical document he's not qualified for." << RESET << std::endl;
    try {
        Bureaucrat bob("Bob Newbie", 120);
        AForm formF003("AForm F-003", 50, 20);
        bob.signForm(formF003); // Bob attempts to sign (should fail)

    } catch (const std::exception &e) {
        std::cerr << RED << "✓ Caught unexpected exception: " << e.what() << RESET << std::endl;
        // signForm() itself handles the exception and prints the error message.
    }
    std::cout << std::endl;

    // 4. The Department Head's Double Check
    std::cout << YELLOW << "4. The Department Head's Double Check: Clara tries to sign an already processed report." << RESET << std::endl;
    try {
        Bureaucrat clara("Clara Head", 25);
        AForm formF004("AForm F-004", 30, 25);
        clara.signForm(formF004); // Clara signs it first time
        clara.signForm(formF004); // Clara tries to sign it again (should just inform it's already signed)
    } catch (const std::exception &e) {
        std::cerr << RED << "✓ Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << YELLOW << "=== ALL TESTS COMPLETED ===" << RESET << std::endl << std::endl;
    return 0;
}