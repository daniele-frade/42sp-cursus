#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor initializes the PhoneBook with zero contacts and sets the oldestIndex to 0
PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}

// Truncate text to a maximum length of 10 characters
std::string PhoneBook::truncateText(const std::string &text) const {
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}

// Method to add a new contact to the phonebook
void PhoneBook::addContact() {
    std::string first, last, nick, phone, secret;
    
    // Prompt user to enter contact details
    std::cout << "Enter the first name: ";
    std::getline(std::cin, first);
    std::cout << "Enter the last name: ";
    std::getline(std::cin, last);
    std::cout << "Enter the nickname: ";
    std::getline(std::cin, nick);
    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, secret);

    if (totalContacts < 8) {
        if (contacts[totalContacts].setContact(first, last, nick, phone, secret)) {
            totalContacts++;
        } else {
            std::cout << "Error: All fields are required. Please make sure to fill in the first name, last name, nickname, phone number, and darkest secret." << std::endl;
        }
    } else {
        if (contacts[oldestIndex].setContact(first, last, nick, phone, secret)) {
            oldestIndex = (oldestIndex + 1) % 8;
        } else {
            std::cout << "Error: All fields are required. Please make sure to fill in the first name, last name, nickname, phone number, and darkest secret." << std::endl;
        }
    }
}

// Method to search and display contacts in the phonebook
void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "The contact list is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << i << "|" << std::setw(10) << truncateText(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateText(contacts[i].getLastName()) << "|" 
                  << std::setw(10) << truncateText(contacts[i].getNickname()) << std::endl;
    }

    int index;
    std::cout << "Enter the contact index to see more details: ";
    std::cin >> index;
    std::cin.ignore();
    
    if (index >= 0 && index < totalContacts) {
        contacts[index].displayContactDetails();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}
