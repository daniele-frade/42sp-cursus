#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical 
AForm::AForm() : name("Default "), isSigned(false), gradeToSign(75), gradeToExecute(75) {
    std::cout << " Default constructor called!" << std::endl;
	validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(AForm const& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << " Copy constructor called!" << std::endl;
	validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

// In this case, name, gradeToSign, gradeToExecute are const, so they cannot be assigned
AForm& AForm::operator=(AForm const& other) {
    std::cout << " Copy assignment operator called!" << std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << " Destructor called!" << std::endl;
}

// Parameterized constructor
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << " Parameterized constructor called!" << std::endl;
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

// Private method to validate grade
void AForm::validateGrade(int grade) const {
    if (grade < 1) {
        throw AForm::GradeTooHighException();
    } else if (grade > 150) {
        throw AForm::GradeTooLowException();
    }
}

// Is signed?
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

// Nested exception classes for grade errors
const char* AForm::GradeTooHighException::what() const throw() {
    return (": Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return (": Grade too low!");
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, AForm const& form) {
    os << YELLOW << form.getName() << RESET
       << ", signed: " << (form.getIsSigned() ? YELLOW "true" RESET : YELLOW "false" RESET)
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << ".";
    return os;
}