#include "Phonebook.hpp"
#include <iostream>

void Phonebook::addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname) {
    for (const auto &contact : contacts) {
        if (contact.getPhoneNumber() == phoneNumber) {
            std::cout << "Phone number must be unique. Contact not added.\n";
            return;
        }
    }
    contacts.emplace_back(name, phoneNumber, nickname);
    std::cout << "Contact added.\n";
}

void Phonebook::displayContactList() {
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i << ": " << contacts[i].getName() << " (" << contacts[i].getNickname() << ")\n";
    }
}

int Phonebook::findContactIndexByPhoneNumber(const std::string &phoneNumber) {
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getPhoneNumber() == phoneNumber) {
            return i;
        }
    }
    return -1;
}

void Phonebook::searchContacts() {
    displayContactList();
    int index;
    std::cout << "Enter contact index to view details: ";
    std::cin >> index;
    if (index >= 0 && index < contacts.size()) {
        contacts[index].displayContact();
        std::cout << "Do you want to bookmark this contact? (y/n): ";
        char bookmark;
        std::cin >> bookmark;
        if (bookmark == 'y' || bookmark == 'Y') {
            contacts[index].setBookmark(true);
            std::cout << "Contact bookmarked.\n";
        }
    } else {
        std::cout << "Invalid index.\n";
    }
}

void Phonebook::removeContact() {
    std::cout << "Enter 1 to remove by index, or 2 to remove by phone number: ";
    int option;
    std::cin >> option;
    if (option == 1) {
        int index;
        std::cout << "Enter index: ";
        std::cin >> index;
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            std::cout << "Contact removed.\n";
        } else {
            std::cout << "Invalid index.\n";
        }
    } else if (option == 2) {
        std::string phoneNumber;
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        int index = findContactIndexByPhoneNumber(phoneNumber);
        if (index != -1) {
            contacts.erase(contacts.begin() + index);
            std::cout << "Contact removed.\n";
        } else {
            std::cout << "Phone number not found.\n";
        }
    } else {
        std::cout << "Invalid option.\n";
    }
}

void Phonebook::listBookmarkedContacts() {
    int i = 0;
    for (const auto &contact : contacts) {
        if (contact.getBookmarkStatus()) {
            contact.displayContact();
            i++;
        }
    }
    if (i == 0) {
        std::cout << "No contacts bookmarked yet.\n";
    }
}
