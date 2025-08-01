#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_pardon", 25, 5, "default_target") {
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", 25, 5, target) {
    std::cout << "PresidentialPardonForm Parameterized constructor called for target: " << target << std::endl;
}

// Override getTarget() if AForm::getTarget() is pure virtual
const std::string& PresidentialPardonForm::getTarget() const {
    return AForm::getTarget();
}

// Specific Action Implementation: Informs that <target> has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::executeAction() const {
    std::cout << GREEN << getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
