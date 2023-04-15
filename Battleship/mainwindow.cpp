
#include "mainwindow.h"

#include "cgamemanagement.h"

#include "ccomputerplayer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    auto gameManagement = new CGameManagement(this);

    ui->setupUi(this);

    ui->_enemyGround->setLabel(ui->_enemyDisplay);
    ui->_playerGround->setLabel(ui->_playerDisplay);

    connect(ui->actionstart, &QAction::triggered, gameManagement, &CGameManagement::initGame);

    gameManagement->initGame();

    new CComputerPlayer(ui->_playerGround, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
