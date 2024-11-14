#include "mainwindow.h"
#include "DialogSearch.h"
#include "ui_mainwindow.h"
#include "Utils.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QRegularExpressionMatch>
#include <qabstractspinbox.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTabContactOrder();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_search_clicked()
{
    DialogSearch searchWindow(phonebook);
    searchWindow.exec();
}

void MainWindow::on_btn_add_clicked()
{
    QString name = ui->text_name->toPlainText();
    QString number = ui->text_number->toPlainText();
    QString email = ui->text_email->toPlainText();
    bool flag = true;

    if (containsNonAlphabetic(name) || name.isEmpty() || name.length() > 25) {
        flag = false;
        ui->text_name->clear();
        QMessageBox::critical(this,"Something Wrong", "Please check your Name!");
    }

    if (flag != false && (!containsOnlyDigits(number) || number.isEmpty() || number.length() > 20)) {
        flag = false;
        ui->text_number->clear();
        QMessageBox::critical(this,"Something Wrong", "Please check your phone number!");
    }

    if (flag != false && (!isValidEmail(email) || email.isEmpty())) {
        flag = false;
        ui->text_email->clear();
        QMessageBox::critical(this,"Something Wrong", "Please check your email!");
    }

    if (flag == true)
    {
        phonebook.addContact(name, number, email);
        QMessageBox::information(this,"Contact created successfully", "Name: "+name+"\nPhone number: "+number+"\nEmail: "+email);
        ui->text_name->clear();
        ui->text_number->clear();
        ui->text_email->clear();
    }

}

void MainWindow::setTabContactOrder()
{
    ui->text_name->setTabChangesFocus(true);
    ui->text_number->setTabChangesFocus(true);
    ui->text_email->setTabChangesFocus(true);

    setTabOrder(ui->text_name, ui->text_number);
    setTabOrder(ui->text_number, ui->text_email);
    setTabOrder(ui->text_email, ui->btn_add);
    setTabOrder(ui->btn_add, ui->btn_search);
}
