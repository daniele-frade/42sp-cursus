#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
		
		// Private method to validate grade
		void validateGrade(int grade) const;

	public:
		// Orthodox Canonical AForm
		Bureaucrat();
		Bureaucrat(Bureaucrat const& other);
		Bureaucrat& operator=(Bureaucrat const& other);
		~Bureaucrat();

		Bureaucrat(const std::string& name, int grade);

		// Getters
		std::string const& getName() const;
		int const& getGrade() const;

		// Increment and decrement grade
		void incrementGrade();
    	void decrementGrade();

		// Função membro para executar um AForm
        void executeForm(AForm const& form) const; 

		// Sign AForm
		void signForm(AForm& form);

		// Nested exception classes for grade errors
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

// ANSI Color codes
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define YELLOW  "\033[33m"
# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define WHITE   "\033[37m"

#endif // BUREAUCRAT_HPP