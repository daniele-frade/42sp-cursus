#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook; // Instance of the PhoneBook class
    std::string command;

    while (true) {
        std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Exiting the program..." << std::endl;
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
