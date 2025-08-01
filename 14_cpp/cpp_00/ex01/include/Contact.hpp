#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
    // Private member variables
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    // Default constructor
    Contact();

    // Method to set contact details
    // Takes five parameters: first name, last name, nickname, phone number, and darkest secret
    bool setContact(const std::string &first, const std::string &last, const std::string &nick, const std::string &phone, const std::string &secret);

    // Getter methods to retrieve contact details
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Method to display all contact details
    void displayContactDetails() const;
};

#endif