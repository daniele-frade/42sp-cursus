#include "Contact.hpp"
#include <iostream>

// Default constructor implementation
Contact::Contact() {}

// Method to set the contact's details
bool Contact::setContact(const std::string &first, const std::string &last, const std::string &nick, const std::string &phone, const std::string &secret) {
    if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) {
        return false;
    }
    // Set the member variables
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
    return true;
}

// Getter method implementations
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

// Method to display the contact's details
void Contact::displayContactDetails() const {
    std::cout << "First Name: " << firstName << "\nLast Name: " << lastName << "\nNickname: " << nickname
              << "\nPhone Number: " << phoneNumber << "\nDarkest Secret: " << darkestSecret << std::endl;
}
