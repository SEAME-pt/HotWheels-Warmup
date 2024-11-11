#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool isBookmarked;

public:
    Contact(const std::string &name, const std::string &phoneNumber, const std::string &nickname);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getNickname() const;
    bool getBookmarkStatus() const;


    void setBookmark(bool bookmarkStatus);
    void displayContact() const;
};

#endif
