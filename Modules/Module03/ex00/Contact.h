#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string name;
    std::string phoneNumber;
    std::string email;


public:
	Contact();
    Contact(const std::string &name, const std::string &phoneNumber, const std::string &email);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    void setName(const std::string &name);
    void setPhoneNumber(const std::string &phoneNumber);
    void setEmail(const std::string &email);

    void displayContact() const;
};

#endif
