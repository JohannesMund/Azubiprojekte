#include "mainwindow.h"
#include "cdisplaylabel.h"
#include "cplayfield.h"
#include "gamemanagement.h"

#include <QComboBox>
#include <QMessageBox>

#include "ui_mainwindow.h"

const unsigned int MainWindow::_defaultFields = 36;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frmDisplay->reset();

    ui->sbNumFields->setMaximum(getMaxFields());
    ui->sbNumFields->setMinimum(2);
    ui->sbNumFields->setSingleStep(2);
    ui->sbNumFields->setValue(getDefaultFields());

    connect(ui->frmPlayfield, &CPlayField::togglePlayer, &GameManagement::toggleCurrentPlayer);
    connect(ui->frmPlayfield, &CPlayField::playerScored, &GameManagement::startGame);
    connect(ui->frmPlayfield, &CPlayField::gameOver, &GameManagement::stopGame);

    connect(ui->frmPlayfield, &CPlayField::togglePlayer, ui->frmDisplay, &CDisplayLabel::togglePlayer);
    connect(ui->frmPlayfield, &CPlayField::playerScored, ui->frmDisplay, &CDisplayLabel::addPoints);
    connect(ui->frmPlayfield, &CPlayField::gameOver, ui->frmDisplay, &CDisplayLabel::gameOver);

    connect(ui->pbReset, &QPushButton::clicked, this, &MainWindow::reset);
    connect(ui->cbGameMode, &QComboBox::currentTextChanged, this, &MainWindow::changeGameMode);
    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    if (GameManagement::isGameRunning() && QMessageBox::question(0,
                                                                 "Spiel läuft",
                                                                 "Es läuft bereits ein Spiel. Abbrechen?",
                                                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    ui->frmPlayfield->init(ensureEven(ui->sbNumFields->value()));
    ui->frmDisplay->reset();
}

int MainWindow::ensureEven(const int i)
{
    if (i % 2 != 0)
    {
        return i + 1;
    }
    return i;
}

int MainWindow::getMaxFields() const
{
    return ensureEven(CPlayField::getMaxFields());
}

int MainWindow::getDefaultFields() const
{
    return std::min(ensureEven(_defaultFields), getMaxFields());
}

void MainWindow::changeGameMode(const QString& mode)
{
}
