#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        
        PresidentialPardonForm(const std::string& target);
        
        // Override getTarget() from AForm
        virtual const std::string& getTarget() const;
        // Override the pure virtual function from AForm to perform the specific action
        virtual void executeAction() const;
};

#endif