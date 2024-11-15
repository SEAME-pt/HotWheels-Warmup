#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "./Contact.h"
#include <qcontainerfwd.h>
#include <vector>
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QStringList>

class Phonebook
{
private:
    std::vector<Contact> contacts;

    int findContactIndexByPhoneNumber(const QString &phoneNumber);

public:
	Phonebook();
    void addContact(const QString &name, const QString &phoneNumber, const QString &nickname);
    void searchContacts();
    void removeContact();
    bool importContacts(const QString &fileName);

    std::vector<Contact>* getContacts();
};

#endif
