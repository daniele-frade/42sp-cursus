#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string& target);
        
        // Override getTarget() from AForm
        virtual const std::string& getTarget() const;
        // Override the pure virtual function from AForm to perform the specific action
        virtual void executeAction() const;
};

#endif