/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label_4;
    QTextEdit *text_email;
    QTextEdit *text_name;
    QTextEdit *text_number;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_add;
    QPushButton *btn_search;
    QLabel *label;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(310, 455);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(310, 455));
        MainWindow->setMaximumSize(QSize(310, 455));
        MainWindow->setStyleSheet(QString::fromUtf8("gridline-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 50, 100, 100));
        label_5->setMinimumSize(QSize(100, 100));
        label_5->setMaximumSize(QSize(0, 0));
        label_5->setSizeIncrement(QSize(0, 0));
        label_5->setBaseSize(QSize(0, 0));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/contact-book_1.png")));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(21, 290, 44, 17));
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        text_email = new QTextEdit(centralwidget);
        text_email->setObjectName("text_email");
        text_email->setGeometry(QRect(21, 313, 269, 30));
        text_email->setMinimumSize(QSize(0, 30));
        text_email->setMaximumSize(QSize(16777215, 30));
        text_name = new QTextEdit(centralwidget);
        text_name->setObjectName("text_name");
        text_name->setGeometry(QRect(21, 177, 269, 30));
        text_name->setMinimumSize(QSize(0, 30));
        text_name->setMaximumSize(QSize(16777215, 30));
        text_name->setLineWidth(2);
        text_number = new QTextEdit(centralwidget);
        text_number->setObjectName("text_number");
        text_number->setGeometry(QRect(21, 245, 269, 30));
        text_number->setMinimumSize(QSize(0, 30));
        text_number->setMaximumSize(QSize(16777215, 30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 154, 43, 17));
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(21, 358, 271, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_add = new QPushButton(layoutWidget);
        btn_add->setObjectName("btn_add");
        btn_add->setMinimumSize(QSize(0, 50));
        btn_add->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(btn_add);

        btn_search = new QPushButton(layoutWidget);
        btn_search->setObjectName("btn_search");
        btn_search->setMinimumSize(QSize(0, 50));
        btn_search->setMaximumSize(QSize(1000, 50));
        btn_search->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        horizontalLayout->addWidget(btn_search);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 11, 271, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setTabletTracking(false);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 222, 118, 17));
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 310, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HOTWHEELS PHONEBOOK", nullptr));
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "NAME", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "ADD CONTACT", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "SEARCH", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Phone Book ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PHONE NUMBER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
