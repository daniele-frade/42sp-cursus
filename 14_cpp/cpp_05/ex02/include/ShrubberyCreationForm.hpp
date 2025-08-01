#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string& target);
        
        // Override getTarget() from AForm
        virtual const std::string& getTarget() const;
        // Override the pure virtual function from AForm to perform the specific action
        virtual void executeAction() const;
};

#endif