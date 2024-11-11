#include "Phonebook.hpp"
#include <algorithm>
#include <iostream>

//
void run() {
  Phonebook phonebook;
  std::string command;
  while (true) {
    std::cout << "Enter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
    std::cin >> command;

    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    if (command == "ADD") {
      std::string name, phoneNumber, nickname;
      std::cout << "Enter name: ";
      std::cin >> name;
      std::cout << "Enter phone number: ";
      std::cin >> phoneNumber;
      std::cout << "Enter nickname: ";
      std::cin >> nickname;
      phonebook.addContact(name, phoneNumber, nickname);
    } else if (command == "SEARCH") {
      phonebook.searchContacts();
    } else if (command == "REMOVE") {
      phonebook.removeContact();
    } else if (command == "BOOKMARK") {
      phonebook.listBookmarkedContacts();
    } else if (command == "EXIT") {
      std::cout << "Shutting down...\n";
      break;
    } else {
      std::cout << "Invalid command.\n";
    }
  }
}

int main() {
  run();
  return 0;
}
