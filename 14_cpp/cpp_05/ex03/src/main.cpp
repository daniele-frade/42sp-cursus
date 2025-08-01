#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << std::endl;
    std::cout << BOLD << YELLOW << "=== EX03: INTERN CLASS TESTS ===" << RESET << std::endl << std::endl;

    Intern someIntern;
    std::cout << std::endl;

    // Test 1: Intern creates a Shrubbery Creation Form
    std::cout << YELLOW << "1. Intern creates Shrubbery Creation Form" << RESET << std::endl;
    AForm* shrubForm = NULL;
    try {
        shrubForm = someIntern.makeForm("shrubbery creation", "Garden_Spot");
        if (shrubForm) {
            std::cout << GREEN << "Form created: " << *shrubForm << RESET << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Intern creates a Robotomy Request Form
    std::cout << YELLOW << "2. Intern creates Robotomy Request Form" << RESET << std::endl;
    AForm* robotForm = NULL;
    try {
        robotForm = someIntern.makeForm("robotomy request", "Marvin");
        if (robotForm) {
            std::cout << GREEN << "Form created: " << *robotForm << RESET << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Intern creates a Presidential Pardon Form
    std::cout << YELLOW << "3. Intern creates Presidential Pardon Form" << RESET << std::endl;
    AForm* pardonForm = NULL;
    try {
        pardonForm = someIntern.makeForm("presidential pardon", "Ford");
        if (pardonForm) {
            std::cout << GREEN << "Form created: " << *pardonForm << RESET << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    //Test 4: Intern tries to create an unknown form
    std::cout << YELLOW << "4. Intern tries to create an UNKNOWN Form" << RESET << std::endl;
    AForm* unknownForm = NULL;
    try {
        unknownForm = someIntern.makeForm("coffee request", "Boss");
        if (unknownForm) {
            std::cout << RED << "Error: Unknown form created unexpectedly: " << *unknownForm << RESET << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "Cleaning up allocated memory" << RESET << std::endl;
    delete shrubForm;
    delete robotForm;
    delete pardonForm;

    std::cout << GREEN << "✓ Dynamically allocated forms deleted." << RESET << std::endl << std::endl;

    std::cout << BOLD << YELLOW << "=== ALL EX03 TESTS COMPLETED ===" << RESET << std::endl << std::endl;
    return 0;
}