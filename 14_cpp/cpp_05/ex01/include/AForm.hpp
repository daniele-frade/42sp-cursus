#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
        // Private method to validate grade
        void validateGrade(int grade) const;
    
    protected:
        std::string target;
    
    public:
        // Orthodox Canonical Form
        AForm();
        AForm(AForm const& other);
        AForm& operator=(AForm const& other);
        ~AForm();

        AForm(std::string const& name, int gradeToSign, int gradeToExecute);

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        bool beSigned(Bureaucrat const& bureaucrat);
        
        // Nested exception classes for grade errors
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, AForm const& form);

// ANSI Color codes
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define YELLOW  "\033[33m"
# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define WHITE   "\033[37m"

#endif