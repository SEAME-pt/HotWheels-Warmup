#include "Phonebook.h"
#include <iostream>

Phonebook::Phonebook() {}

void Phonebook::addContact(const std::string &name, const std::string &phoneNumber, const std::string &email)
{
	Contact newContact(name, phoneNumber, email);
	contacts.push_back(newContact);
}

void Phonebook::searchContacts()
{
	std::string phoneNumber;

	int index = findContactIndexByPhoneNumber(phoneNumber);

	if (index != -1)
	{
		contacts[index].displayContact();
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}

void Phonebook::removeContact()
{
	std::string phoneNumber;

	int index = findContactIndexByPhoneNumber(phoneNumber);

	if (index != -1)
	{
		contacts.erase(contacts.begin() + index);
		std::cout << "Contact removed" << std::endl;
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}

int Phonebook::findContactIndexByPhoneNumber(const std::string &phoneNumber)
{
	for (int i = 0; i < contacts.size(); i++)
	{
		if (contacts[i].getPhoneNumber() == phoneNumber)
		{
			return i;
		}
	}

	return -1;
}