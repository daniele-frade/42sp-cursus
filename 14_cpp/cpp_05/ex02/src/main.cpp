#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {

    std::cout << std::endl;
    std::cout << BOLD << YELLOW << "=== EX02: ABSTRACT FORMS AND EXECUTION TESTS ===" << RESET << std::endl << std::endl;

    // Test 1: ShrubberyCreationForm (Sign and Execute)
    std::cout << YELLOW << "1. Shrubbery Creation Form Test" << RESET << std::endl;
    try {
        Bureaucrat gardener("Bob the Gardener", 130);
        ShrubberyCreationForm shrubForm("home");

        gardener.signForm(shrubForm);
        std::cout << shrubForm << std::endl;

        // A file named 'home_shrubbery' should be created
        gardener.executeForm(shrubForm);
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: RobotomyRequestForm (Sign, Execute Success/Fail)
    std::cout << YELLOW << "2. Robotomy Request Form Test" << RESET << std::endl;
    try {
        Bureaucrat doctor("Dr. Robotnik", 40);
        RobotomyRequestForm robotomyForm("Bender");

        doctor.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;

        std::cout << "Attempting Robotomy (50% chance of success):" << std::endl;
        doctor.executeForm(robotomyForm);
        // This will print success/failure messages
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    //3: PresidentialPardonForm (Sign, Execute Failure: Grade Too Low)
    std::cout << YELLOW << "3. Presidential Pardon Form Test (Failure)" << RESET << std::endl;
    try {
        Bureaucrat intern("Clerk Newbie", 10);
        Bureaucrat president("Zaphod Beeblebrox", 1);
        PresidentialPardonForm pardonForm("Arthur Dent");

        president.signForm(pardonForm);
        std::cout << pardonForm << std::endl;

        std::cout << "Clerk Newbie tries to execute (should fail due to low grade):" << std::endl;
        intern.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cerr << RED << "Caught unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << YELLOW << "=== ALL EX02 TESTS COMPLETED ===" << RESET << std::endl << std::endl;
    return 0;
}