#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : name("Bureaucrat Master"), grade(150) {
	std::cout << "Default constructor of Bureaucrat called!" << std::endl;
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name) {
	std::cout << "Copy constructor of Bureaucrat called!" << std::endl;
	this->grade = other.grade;
	validateGrade(other.grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
	std::cout << "Copy assignment operator of Bureaucrat called!" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
	validateGrade(grade);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Default Destructor of Bureaucrat called!" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name) {
	std::cout << "Parameterized constructor of Bureaucrat called!" << std::endl;
	this->grade = grade;
	validateGrade(grade);
}

// Getters
std::string const& Bureaucrat::getName() const {
	return name;
}

int const& Bureaucrat::getGrade() const {
	return grade;
}

// Increment and decrement grade
void Bureaucrat::incrementGrade() {
    std::cout << "Attempting to increment " << name << "'s grade from " << grade;
    grade--;
    std::cout << " to " << grade << std::endl;
	validateGrade(grade);
}

void Bureaucrat::decrementGrade() {
    std::cout << "Attempting to decrement " << name << "'s grade from " << grade;
    grade++;
    std::cout << " to " << grade << std::endl;
	validateGrade(grade);
}

// Private method to validate grade
void Bureaucrat::validateGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Nested exception classes for grade errors
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}