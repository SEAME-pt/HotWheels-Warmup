#include "Contact.h"

Contact::Contact() 
{
	this->name = "";
	this->phoneNumber = "";
	this->email = "";
}

Contact::Contact(const std::string &name, const std::string &phoneNumber, const std::string &email) 
{
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
}

std::string Contact::getName() const
{
	return this->name;
}

std::string Contact::getPhoneNumber() const 
{
	return this->phoneNumber;
}

std::string Contact::getEmail() const 
{
	return this->email;
}

void Contact::setName(const std::string &name) 
{
	this->name = name;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) 
{
	this->phoneNumber = phoneNumber;
}

void Contact::setEmail(const std::string &email) 
{
	this->email = email;
}