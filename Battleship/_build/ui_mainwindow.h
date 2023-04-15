/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ccomputerbattlefield.h"
#include "ccomputerbattlefieldlabel.h"
#include "cplayerbattlefield.h"
#include "cplayerbattlefieldlabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionstart;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *_enemyShoutbox;
    CPlayerBattleFieldLabel *_playerDisplay;
    QVBoxLayout *verticalLayout_2;
    CComputerBattleField *_enemyGround;
    CPlayerBattleField *_playerGround;
    QVBoxLayout *verticalLayout;
    CComputerBattleFieldLabel *_enemyDisplay;
    QLabel *_playerShoutBox;
    QMenuBar *menubar;
    QMenu *menunew_game;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 600);
        actionstart = new QAction(MainWindow);
        actionstart->setObjectName(QString::fromUtf8("actionstart"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        _enemyShoutbox = new QLabel(centralwidget);
        _enemyShoutbox->setObjectName(QString::fromUtf8("_enemyShoutbox"));

        verticalLayout_3->addWidget(_enemyShoutbox);

        _playerDisplay = new CPlayerBattleFieldLabel(centralwidget);
        _playerDisplay->setObjectName(QString::fromUtf8("_playerDisplay"));

        verticalLayout_3->addWidget(_playerDisplay);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        _enemyGround = new CComputerBattleField(centralwidget);
        _enemyGround->setObjectName(QString::fromUtf8("_enemyGround"));
        _enemyGround->setFrameShape(QFrame::StyledPanel);
        _enemyGround->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(_enemyGround);

        _playerGround = new CPlayerBattleField(centralwidget);
        _playerGround->setObjectName(QString::fromUtf8("_playerGround"));
        _playerGround->setFrameShape(QFrame::StyledPanel);
        _playerGround->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(_playerGround);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _enemyDisplay = new CComputerBattleFieldLabel(centralwidget);
        _enemyDisplay->setObjectName(QString::fromUtf8("_enemyDisplay"));

        verticalLayout->addWidget(_enemyDisplay);

        _playerShoutBox = new QLabel(centralwidget);
        _playerShoutBox->setObjectName(QString::fromUtf8("_playerShoutBox"));

        verticalLayout->addWidget(_playerShoutBox);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 21));
        menunew_game = new QMenu(menubar);
        menunew_game->setObjectName(QString::fromUtf8("menunew_game"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menunew_game->menuAction());
        menunew_game->addAction(actionstart);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionstart->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        _enemyShoutbox->setText(QString());
        _playerDisplay->setText(QString());
        _enemyDisplay->setText(QString());
        _playerShoutBox->setText(QString());
        menunew_game->setTitle(QCoreApplication::translate("MainWindow", "new game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
