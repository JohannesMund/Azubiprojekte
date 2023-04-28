
#include "mainwindow.h"

#include "cgamemanagement.h"

#include "ccomputerplayer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    auto gameManagement = new CGameManagement(this);

    ui->setupUi(this);

    gameManagement->setShoutBox(ui->_enemyShoutbox);

    ui->_enemyGround->setLabel(ui->_enemyDisplay);
    ui->_playerGround->setLabel(ui->_playerDisplay);

    connect(ui->_actionStartEasy,
            &QAction::triggered,
            gameManagement,
            []() { CGameManagement::getInstance()->initGame(CGameManagement::EDifficulty::eEasy); });

    connect(ui->_actionStartMedium,
            &QAction::triggered,
            gameManagement,
            []() { CGameManagement::getInstance()->initGame(CGameManagement::EDifficulty::eMedium); });

    connect(ui->_actionStartHard,
            &QAction::triggered,
            gameManagement,
            []() { CGameManagement::getInstance()->initGame(CGameManagement::EDifficulty::eHard); });

    gameManagement->initGame(CGameManagement::EDifficulty::eMedium);

    new CComputerPlayer(ui->_playerGround, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
