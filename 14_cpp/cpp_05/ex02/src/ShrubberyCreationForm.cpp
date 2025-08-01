#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_shrubbery", 145, 137, "default_target") {
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other); // Call base class assignment operator
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137, target) {
    std::cout << "ShrubberyCreationForm Parameterized constructor called for target: " << target << std::endl;
}

// Override getTarget() if AForm::getTarget()
const std::string& ShrubberyCreationForm::getTarget() const {
    return AForm::getTarget();
}

// Specific Action Implementation: Creates a file named <target>_shrubbery and writes ASCII trees into it
void ShrubberyCreationForm::executeAction() const {
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream ofs(filename.c_str());

    if (!ofs.is_open()) {
        std::cerr << RED << "Error: Could not open file " << filename << RESET << std::endl;
        return;
    }

    // ASCII tree art
    ofs << "      /\\      " << std::endl;
    ofs << "     /\\*\\     " << std::endl;
    ofs << "    /\\O\\*\\    " << std::endl;
    ofs << "   /\\/\\/\\/\\   " << std::endl;
    ofs << "  /\\O\\/\\O\\*\\  " << std::endl;
    ofs << " /\\*\\/\\O\\/\\/\\ " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << std::endl;
    ofs << "      /\\      " << std::endl;
    ofs << "     /\\*\\     " << std::endl;
    ofs << "    /\\O\\*\\    " << std::endl;
    ofs << "   /\\/\\/\\/\\   " << std::endl;
    ofs << "  /\\O\\/\\O\\*\\  " << std::endl;
    ofs << " /\\*\\/\\O\\/\\/\\ " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs.close();
    std::cout << GREEN << "Shrubbery created successfully in " << filename << RESET << std::endl;
}