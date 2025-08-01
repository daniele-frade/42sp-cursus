#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// Include the Contact class header to use Contact objects
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    int oldestIndex;

    // Helper method to truncate text to a specific length
    std::string truncateText(const std::string &text) const;

public:
    PhoneBook();

    void addContact();
    void searchContacts() const;
};

#endif
