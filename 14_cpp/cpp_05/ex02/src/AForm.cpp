#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical AForm
AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(75), gradeToExecute(75), target("default_target"){
    std::cout << "AForm Default constructor called!" << std::endl;
	validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(AForm const& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {
    std::cout << "AForm Copy constructor called!" << std::endl;
	validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm& AForm::operator=(AForm const& other) {
    std::cout << "AForm Copy assignment operator called!" << std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm Destructor called!" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
    std::cout << "AForm Parameterized constructor called!" << std::endl;
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

// Getters
const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return target;
}

// Private method to validate grade
void AForm::validateGrade(int grade) const {
    if (grade < 1) {
        throw AForm::GradeTooHighException();
    } else if (grade > 150) {
        throw AForm::GradeTooLowException();
    }
}

bool AForm::beSigned(Bureaucrat const& bureaucrat) {
    if (isSigned) {
        std::cout << name << " is already signed." << std::endl;
        return false;
    }
    if (bureaucrat.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
    return isSigned;
}

// This method handles the common validation logic before calling the specific action
void AForm::execute(Bureaucrat const& executor) const {
    if (!isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) { 
        throw GradeTooLowException();
    }
    // If all checks pass, call the specific action implemented by the derived class.
    this->executeAction();
}

// Nested exception classes for grade errors
const char* AForm::GradeTooHighException::what() const throw() {
    return ("AForm: Grade too high!");
}
const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm: Grade too low!");
}
const char* AForm::FormNotSignedException::what() const throw() {
    return ("AForm: Form not signed!");
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << YELLOW << form.getName() << RESET
       << ", signed: " << (form.getIsSigned() ? YELLOW "true" RESET : YELLOW "false" RESET)
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << ".";
    return os;
}