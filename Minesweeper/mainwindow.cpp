#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cplayfield.h"

#include <QActionGroup>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
    newGame();
    connect(ui->playField, &CPlayField::gameOver, ui->display, &CDisplay::setGameOver);
    connect(ui->playField, &CPlayField::buttonFlagged, ui->display, &CDisplay::addRevealedBomb);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{

    QAction* newGame = new QAction("neues Spiel", this);
    connect(newGame, &QAction::triggered, this, &MainWindow::newGame);

    ui->menuGame->insertAction(0, newGame);

    QAction* a1 = new QAction("S", this);
    a1->setCheckable(true);
    QAction* a2 = new QAction("M", this);
    a2->setCheckable(true);
    QAction* a3 = new QAction("L", this);
    a3->setCheckable(true);
    QAction* a4 = new QAction("XL", this);
    a4->setCheckable(true);

    _playFieldSizeActions = new QActionGroup(this);
    _playFieldSizeActions->setExclusive(true);
    _playFieldSizeActions->addAction(a1);
    _playFieldSizeActions->addAction(a2);
    _playFieldSizeActions->addAction(a3);
    _playFieldSizeActions->addAction(a4);
    _playFieldSizeActions->actions().at(0)->setChecked(true);

    ui->menuSize->insertActions(0, _playFieldSizeActions->actions());

    QAction* b1 = new QAction("wenig", this);
    b1->setCheckable(true);
    QAction* b2 = new QAction("mittel", this);
    b2->setCheckable(true);
    QAction* b3 = new QAction("viele", this);
    b3->setCheckable(true);
    QAction* b4 = new QAction("ein Arsch voll", this);
    b4->setCheckable(true);

    _bombCountActions = new QActionGroup(this);
    _bombCountActions->setExclusive(true);
    _bombCountActions->addAction(b1);
    _bombCountActions->addAction(b2);
    _bombCountActions->addAction(b3);
    _bombCountActions->addAction(b4);
    _bombCountActions->actions().at(0)->setChecked(true);

    ui->menuBombs->insertActions(0, _bombCountActions->actions());
}

void MainWindow::newGame()
{
    CPlayField::PlayFieldSize sz;

    if (_playFieldSizeActions->actions().at(0)->isChecked())
        sz = CPlayField::PlayFieldSize::s;
    else if (_playFieldSizeActions->actions().at(1)->isChecked())
        sz = CPlayField::PlayFieldSize::m;
    else if (_playFieldSizeActions->actions().at(2)->isChecked())
        sz = CPlayField::PlayFieldSize::l;
    else if (_playFieldSizeActions->actions().at(3)->isChecked())
        sz = CPlayField::PlayFieldSize::xl;
    else
        sz = CPlayField::PlayFieldSize::s;

    CPlayField::BombCount bc;

    if (_bombCountActions->actions().at(0)->isChecked())
        bc = CPlayField::BombCount::little;
    else if (_bombCountActions->actions().at(1)->isChecked())
        bc = CPlayField::BombCount::few;
    else if (_bombCountActions->actions().at(2)->isChecked())
        bc = CPlayField::BombCount::many;
    else if (_bombCountActions->actions().at(3)->isChecked())
        bc = CPlayField::BombCount::shitLoad;
    else
        bc = CPlayField::BombCount::little;

    ui->playField->init(sz, bc);
    resize(ui->playField->size());
    ui->display->setBombs(ui->playField->getNumBombs());
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    resize(ui->playField->size());
}
