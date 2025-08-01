#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other; // Cast to void to suppress unused parameter warning
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other; // Cast to void to suppress unused parameter warning
    std::cout << "Intern Copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}


struct FormPair {
    const char* name;
    AForm* (*creator)(const std::string&);
};

// Funções "fábrica" para cada tipo de formulário
AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPardon(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    static FormPair forms[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPardon }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i].name)
            return forms[i].creator(target);
    }

    std::cout << RED << "Error: Intern cannot create form " << formName << " because it doesn't exist!" << RESET << std::endl;
    return NULL;
}