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

bool Phonebook::importContacts(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << fileName;
        return false;
    }

    QTextStream in(&file);
    QString name, phoneNumber, email;
    bool contactInProgress = false;

    int i = 0;
    // Read the file line by line and process contact info
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Remove extra spaces

        // Match each field with a regular expression
        if (line.startsWith("Name:") && i == 0) {
            name = line.mid(5).trimmed();  // Extract name after "Name: "
            i++;
        }
        else if (line.startsWith("Phone Number:") && i == 1) {
            phoneNumber = line.mid(14).trimmed();
            i++;
        }
        else if (line.startsWith("Email:") && i == 2) {
            email = line.mid(6).trimmed();
            i++;
        }
        else {
            i = 0;
        }

        if (i == 3) {
            addContact(name, phoneNumber, email);
            i = 0;
        }

    }
    file.close();

    return true;
};

std::vector<Contact>* Phonebook::getContacts()
{
    return &this->contacts;
}
