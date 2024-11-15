/********************************************************************************
** Form generated from reading UI file 'RacingGame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACINGGAME_H
#define UI_RACINGGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RacingGame
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *exitButton;
    QPushButton *pauseButton;
    QGraphicsView *racingTrackView;
    QPushButton *resetButton;

    void setupUi(QMainWindow *RacingGame)
    {
        if (RacingGame->objectName().isEmpty())
            RacingGame->setObjectName("RacingGame");
        RacingGame->resize(800, 600);
        centralwidget = new QWidget(RacingGame);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(80, 510, 89, 25));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(280, 510, 89, 25));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(180, 510, 89, 25));
        racingTrackView = new QGraphicsView(centralwidget);
        racingTrackView->setObjectName("racingTrackView");
        racingTrackView->setGeometry(QRect(10, 10, 781, 461));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(650, 520, 89, 25));
        RacingGame->setCentralWidget(centralwidget);

        retranslateUi(RacingGame);

        QMetaObject::connectSlotsByName(RacingGame);
    } // setupUi

    void retranslateUi(QMainWindow *RacingGame)
    {
        RacingGame->setWindowTitle(QCoreApplication::translate("RacingGame", "RacingGame", nullptr));
        startButton->setText(QCoreApplication::translate("RacingGame", "Start", nullptr));
        exitButton->setText(QCoreApplication::translate("RacingGame", "Exit", nullptr));
        pauseButton->setText(QCoreApplication::translate("RacingGame", "Pause", nullptr));
        resetButton->setText(QCoreApplication::translate("RacingGame", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RacingGame: public Ui_RacingGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACINGGAME_H
