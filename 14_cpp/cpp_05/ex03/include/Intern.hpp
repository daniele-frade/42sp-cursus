#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // The key ability of the Intern: creates forms
        // Returns a pointer to an AForm object, or NULL if formName is unknown
        AForm* makeForm(const std::string& formName, const std::string& target);
};

// ANSI Color
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define YELLOW  "\033[33m"
# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define WHITE   "\033[37m"

#endif