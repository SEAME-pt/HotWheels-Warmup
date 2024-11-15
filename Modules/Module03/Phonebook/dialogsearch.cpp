#include "DialogSearch.h"
#include "ui_dialogsearch.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QStringList>


DialogSearch::DialogSearch(Phonebook &phonebook, QWidget *parent) : QDialog(parent), ui(new Ui::DialogSearch), phonebookRef(phonebook)
{
    ui->setupUi(this);
    displayContactList(phonebook);
}

DialogSearch::~DialogSearch()
{
    delete ui;
}

void DialogSearch::displayContactList(Phonebook &phonebook)
{
    ui->listContacts->clear();
    std::vector<Contact> list = *phonebook.getContacts();
    for (const auto &contact : list)
    {
        ui->listContacts->addItem(contact.getName());
    }
}

void DialogSearch::on_btn_viewContact_clicked()
{
    QListWidgetItem *selectedItem = ui->listContacts->currentItem();

    if (selectedItem) {
        QString selectedName = selectedItem->text();

        std::vector<Contact> contacts = *phonebookRef.getContacts();
        for (const auto &contact : contacts) {
            if (contact.getName() == selectedName) {
                ui->label_name->setText(contact.getName());
                ui->label_number->setText(contact.getPhoneNumber());
                ui->label_email->setText(contact.getEmail());
            }
        }
    }
}

void DialogSearch::on_btn_removeContact_clicked()
{
    QListWidgetItem *selectedItem = ui->listContacts->currentItem();
    QMessageBox::StandardButton reply;

    if (selectedItem) {
        reply = QMessageBox::question(this, "Confirm", "Wish to continue?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString selectedName = selectedItem->text();

            std::vector<Contact> *contacts = phonebookRef.getContacts();
            for (auto it = contacts->begin(); it != contacts->end(); ++it) {
                if (it->getName() == selectedName) {
                    delete ui->listContacts->takeItem(ui->listContacts->row(selectedItem));

                    ui->label_name->clear();
                    ui->label_number->clear();
                    ui->label_email->clear();

                    contacts->erase(it);
                    break;
                }
            }
        }
    }
}

void DialogSearch::on_btn_importContactList_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Contact List", "", "Text Files (*.txt);;CSV Files (*.csv)");

    if (!fileName.isEmpty()) {
        if (this->phonebookRef.importContacts(fileName)) {
            QMessageBox::information(this, "Success", "Contacts imported successfully!");
        } else {
            QMessageBox::warning(this, "Error", "Failed to import contacts.");
        }
    }
}

void DialogSearch::on_btn_Reload_clicked()
{
    displayContactList(phonebookRef);
}
