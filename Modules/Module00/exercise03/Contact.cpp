#include "Contact.hpp"

Contact::Contact(const std::string &name, const std::string &phoneNumber, const std::string &nickname)
    : name(name), phoneNumber(phoneNumber), nickname(nickname), isBookmarked(false) {}

std::string Contact::getName() const { return name; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getNickname() const { return nickname; }
bool Contact::getBookmarkStatus() const { return isBookmarked; }

void Contact::setBookmark(bool bookmarkStatus) { isBookmarked = bookmarkStatus; }

void Contact::displayContact() const {
    std::cout << "-------------------\n";
    std::cout << "Name: " << name << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "Nickname: " << nickname << "\n"
              << "Bookmarked: " << (isBookmarked ? "Yes" : "No") << std::endl;
    std::cout << "-------------------\n";
}
