#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default_robotomy", 72, 45, "default_target") {
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45, target) {
    std::cout << "RobotomyRequestForm Parameterized constructor called for target: " << target << std::endl;
}

// Override getTarget() if AForm::getTarget() is pure virtual
const std::string& RobotomyRequestForm::getTarget() const {
    return AForm::getTarget();
}

// Specific Action Implementation: Makes drilling noises and has a 50% chance of success
void RobotomyRequestForm::executeAction() const {
    // Seed the random number generator once for RobotomyRequestForm
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << GREEN << getTarget() << " has been robotomized successfully!" << RESET << std::endl;
    } else {
        std::cout << RED << "Robotomy failed on " << getTarget() << "." << RESET << std::endl;
    }
}