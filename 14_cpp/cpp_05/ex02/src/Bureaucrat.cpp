#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Orthodox Canonical AForm
Bureaucrat::Bureaucrat() : name("Bureaucrat Master"), grade(150) {
	std::cout << "Default constructor of Bureaucrat called!" << std::endl;
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {
	std::cout << "Copy constructor of Bureaucrat called!" << std::endl;
	validateGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
	std::cout << "Copy assignment operator of Bureaucrat called!" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	validateGrade(grade);
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Default Destructor of Bureaucrat called!" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	std::cout << "Parameterized constructor of Bureaucrat called!" << std::endl;
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

// Sign AForm: It will call AForm::beSigned and handle potential exceptions
void Bureaucrat::signForm(AForm& form) {
    try {
		std::cout << this->name << " is trying to sign " << form.getName() << "." << std::endl;
		if (form.beSigned(*this))
		    std::cout << GREEN << this->name << " signed " << form.getName() << "." << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << this->name << " couldn't sign " << form.getName() << " because " << e.what() << "." << RESET << std::endl;
    }
}

// Implementação do método executeForm
void Bureaucrat::executeForm(AForm const& form) const {
    try {
        // Tenta executar o formulário. O AForm::execute() é que faz as validações
        // (se está assinado e se o grau do executor é suficiente) e lança exceções.
        form.execute(*this);
        std::cout << GREEN << name << " executed " << form.getName() << "." << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << name << " couldn't execute " << form.getName() << " because " << e.what() << "." << RESET << std::endl;
    }
}

// Nested exception classes for grade errors
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Overload of the insertion operator for Bureaucrat objects
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}