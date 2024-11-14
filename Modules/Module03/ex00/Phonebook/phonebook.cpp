#include "Phonebook.h"
#include <iostream>
#include "Contact.h"

Phonebook::Phonebook() {}

void Phonebook::addContact(const QString &name, const QString &phoneNumber, const QString &email)
{
	Contact newContact(name, phoneNumber, email);
	contacts.push_back(newContact);
}

void Phonebook::searchContacts()
{
    QString phoneNumber;

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
    QString phoneNumber;

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

int Phonebook::findContactIndexByPhoneNumber(const QString &phoneNumber)
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

std::vector<Contact>* Phonebook::getContacts()
{
    return &this->contacts;
}
