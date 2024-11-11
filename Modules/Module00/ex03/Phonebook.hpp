#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <unordered_map>
#include <vector>
#include <string>

class Phonebook {
private:
    std::vector<Contact> contacts;
    std::unordered_map<std::string, std::string> responses;

    void displayContactList();
    int findContactIndexByPhoneNumber(const std::string &phoneNumber);
    void loadResponses(const std::string &filename);

public:
    Phonebook();
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname);
    void searchContacts();
    void removeContact();
    void listBookmarkedContacts();
};

#endif
