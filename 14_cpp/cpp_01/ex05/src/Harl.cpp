#include "Harl.hpp"

// Prints the 'level' msg
void Harl::debug(void) {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void) {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}
void Harl::warning(void) {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years!" << std::endl;
}
void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

// This function determines which level was passed and calls the appropriate function
void Harl::complain(std::string level) {

    // Array of available levels (DEBUG, INFO, WARNING, ERROR)
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Array of pointers to member functions corresponding to the levels
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Loop through the levels and find a match with the input `level`
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // Calls the corresponding function using a pointer to member function
			(this->*functions[i])();
            return;
        }
    }

    // If no valid level is found, prints an error message
    std::cout << "Invalid level!" << std::endl;
}
