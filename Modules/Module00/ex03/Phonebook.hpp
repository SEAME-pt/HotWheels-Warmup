#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <vector>

class Phonebook {
private:
    std::vector<Contact> contacts;

    void displayContactList();
    int findContactIndexByPhoneNumber(const std::string &phoneNumber);

public:
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname);
    void searchContacts();
    void removeContact();
    void listBookmarkedContacts();
};

#endif
