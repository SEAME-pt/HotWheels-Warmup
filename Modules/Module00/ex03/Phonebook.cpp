#include "Phonebook.hpp"
#include <iostream>
#include <fstream>

// Constructor that loads responses from file
Phonebook::Phonebook() {
    loadResponses("responses.txt");
}

// Function to load responses from a file into the `responses` map
void Phonebook::loadResponses(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        auto delimiterPos = line.find("=");
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        responses[key] = value;
    }
}

// Adds a contact if the phone number is unique
void Phonebook::addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname) {
    for (const auto &contact : contacts) {
        if (contact.getPhoneNumber() == phoneNumber) {
            std::cout << "Phone number must be unique. Contact not added.\n";
            return;
        }
    }
    contacts.emplace_back(name, phoneNumber, nickname);
    std::cout << responses["ADD_SUCCESS"] << "\n";
}

// Displays the contact list with indices
void Phonebook::displayContactList() {
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i << ": " << contacts[i].getName() << " (" << contacts[i].getNickname() << ")\n";
    }
}

// Searches for contacts and optionally bookmarks one
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
            std::cout << responses["BOOKMARK_SUCCESS"] << "\n";
        }
    } else {
        std::cout << "Invalid index.\n";
    }
}

// Removes a contact by index or phone number
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
            std::cout << responses["REMOVE_SUCCESS"] << "\n";
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
            std::cout << responses["REMOVE_SUCCESS"] << "\n";
        } else {
            std::cout << "Phone number not found.\n";
        }
    } else {
        std::cout << "Invalid option.\n";
    }
}

// Finds a contact index by phone number
int Phonebook::findContactIndexByPhoneNumber(const std::string &phoneNumber) {
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getPhoneNumber() == phoneNumber) {
            return i;
        }
    }
    return -1;
}

// Lists all bookmarked contacts
void Phonebook::listBookmarkedContacts() {
    int count = 0;
    for (const auto &contact : contacts) {
        if (contact.getBookmarkStatus()) {
            contact.displayContact();
            count++;
        }
    }

    if (count == 0) {
        std::cout << responses["EMPTY_LIST"] << "\n";
    }
}
