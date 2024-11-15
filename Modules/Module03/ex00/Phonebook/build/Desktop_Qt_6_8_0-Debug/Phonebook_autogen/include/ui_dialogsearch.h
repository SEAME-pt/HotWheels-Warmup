/********************************************************************************
** Form generated from reading UI file 'dialogsearch.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSEARCH_H
#define UI_DIALOGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSearch
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listContacts;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_viewContact;
    QLabel *label_email;
    QLabel *label_name;
    QLabel *label_number;
    QPushButton *btn_removeContact;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *DialogSearch)
    {
        if (DialogSearch->objectName().isEmpty())
            DialogSearch->setObjectName("DialogSearch");
        DialogSearch->resize(471, 455);
        DialogSearch->setMinimumSize(QSize(471, 455));
        DialogSearch->setMaximumSize(QSize(471, 455));
        DialogSearch->setAutoFillBackground(false);
        DialogSearch->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(DialogSearch);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 432, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listContacts = new QListWidget(layoutWidget);
        listContacts->setObjectName("listContacts");
        listContacts->setMinimumSize(QSize(430, 160));
        listContacts->setMaximumSize(QSize(430, 160));

        verticalLayout->addWidget(listContacts);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        btn_viewContact = new QPushButton(layoutWidget);
        btn_viewContact->setObjectName("btn_viewContact");
        btn_viewContact->setMinimumSize(QSize(0, 50));
        btn_viewContact->setMaximumSize(QSize(16777215, 50));
        btn_viewContact->setAutoDefault(false);

        horizontalLayout->addWidget(btn_viewContact);


        verticalLayout->addLayout(horizontalLayout);

        label_email = new QLabel(DialogSearch);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(59, 344, 391, 31));
        label_email->setStyleSheet(QString::fromUtf8("border: 1px solid grey;"));
        label_email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_name = new QLabel(DialogSearch);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(59, 246, 391, 31));
        label_name->setStyleSheet(QString::fromUtf8("border: 1px solid grey;"));
        label_name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_name->setWordWrap(false);
        label_number = new QLabel(DialogSearch);
        label_number->setObjectName("label_number");
        label_number->setGeometry(QRect(59, 294, 391, 31));
        label_number->setStyleSheet(QString::fromUtf8("border: 1px solid grey;"));
        label_number->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        btn_removeContact = new QPushButton(DialogSearch);
        btn_removeContact->setObjectName("btn_removeContact");
        btn_removeContact->setGeometry(QRect(21, 390, 431, 50));
        btn_removeContact->setMinimumSize(QSize(0, 50));
        btn_removeContact->setMaximumSize(QSize(16777215, 50));
        btn_removeContact->setAutoDefault(false);
        label = new QLabel(DialogSearch);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 246, 30, 30));
        label->setPixmap(QPixmap(QString::fromUtf8(":/name_icon.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(DialogSearch);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 295, 30, 30));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/number_icon.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(DialogSearch);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 344, 30, 30));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/email_icon.png")));
        label_3->setScaledContents(true);

        retranslateUi(DialogSearch);

        QMetaObject::connectSlotsByName(DialogSearch);
    } // setupUi

    void retranslateUi(QDialog *DialogSearch)
    {
        DialogSearch->setWindowTitle(QCoreApplication::translate("DialogSearch", "CONTACTS", nullptr));
        btn_viewContact->setText(QCoreApplication::translate("DialogSearch", "SELECT CONTACT", nullptr));
        label_email->setText(QString());
        label_name->setText(QString());
        label_number->setText(QString());
        btn_removeContact->setText(QCoreApplication::translate("DialogSearch", "REMOVE CONTACT", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogSearch: public Ui_DialogSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSEARCH_H
