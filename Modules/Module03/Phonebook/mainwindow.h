#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Phonebook.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTabContactOrder();

private slots:
    void on_btn_search_clicked();
    void on_btn_add_clicked();

private:
    Ui::MainWindow *ui;
    Phonebook phonebook;

};
#endif // MAINWINDOW_H
