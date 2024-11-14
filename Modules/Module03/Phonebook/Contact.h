#ifndef CONTACT_H
#define CONTACT_H


#include <qcontainerfwd.h>
#include <qobject.h>

class Contact
{
private:
    QString name;
    QString phoneNumber;
    QString email;


public:
	Contact();
    Contact(const QString &name, const QString &phoneNumber, const QString &email);

    QString getName() const;
    QString getPhoneNumber() const;
    QString getEmail() const;

    void setName(const QString &name);
    void setPhoneNumber(const QString &phoneNumber);
    void setEmail(const QString &email);

    void displayContact() const;
};

#endif
