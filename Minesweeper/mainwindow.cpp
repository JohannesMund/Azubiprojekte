#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cplayfield.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playField->init();
    ui->display->setBombs(ui->playField->getNumBombs());
    connect(ui->playField, &CPlayField::gameOver, ui->display, &CDisplay::setGameOver);
    connect(ui->playField, &CPlayField::buttonFlagged, ui->display, &CDisplay::addRevealedBomb);

    resize(ui->playField->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    resize(ui->playField->size());
}
