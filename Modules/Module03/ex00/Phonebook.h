#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "./Contact.h"
#include <vector>

class Phonebook
{
private:
    std::vector<Contact> contacts;

    void displayContactList();
    int findContactIndexByPhoneNumber(const std::string &phoneNumber);

public:
	Phonebook();
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname);
    void searchContacts();
    void removeContact();
};

#endif
