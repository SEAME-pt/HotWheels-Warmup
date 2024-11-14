#include "Contact.h"

Contact::Contact() 
{
	this->name = "";
	this->phoneNumber = "";
	this->email = "";
}

Contact::Contact(const QString &name, const QString &phoneNumber, const QString &email)
{
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
}

QString Contact::getName() const
{
	return this->name;
}

QString Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

QString Contact::getEmail() const
{
	return this->email;
}

void Contact::setName(const QString &name)
{
	this->name = name;
}

void Contact::setPhoneNumber(const QString &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setEmail(const QString &email)
{
	this->email = email;
}

void Contact::displayContact() const {}
