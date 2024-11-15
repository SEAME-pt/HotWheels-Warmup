#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include "Phonebook.h"
#include <QDialog>

namespace Ui {
class DialogSearch;
}

class DialogSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearch(Phonebook &phonebook, QWidget *parent = nullptr);
    ~DialogSearch();

private slots:
    void displayContactList(Phonebook &phonebook);
    void on_btn_viewContact_clicked();
    void on_btn_removeContact_clicked();
    void on_btn_importContactList_clicked();
    void on_btn_Reload_clicked();
private:
    Ui::DialogSearch *ui;
    Phonebook &phonebookRef; // Referência ao objeto Phonebook

};

#endif // DIALOGSEARCH_H
