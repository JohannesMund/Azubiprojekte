#include "mainwindow.h"
#include "cdisplaylabel.h"
#include "cplayfield.h"

#include <QMessageBox>

#include "ui_mainwindow.h"

const unsigned int MainWindow::_defaultFields = 36;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lDisplay->reset();

    ui->sbNumFields->setMaximum(getMaxFields());
    ui->sbNumFields->setMinimum(2);
    ui->sbNumFields->setSingleStep(2);
    ui->sbNumFields->setValue(getDefaultFields());

    connect(ui->frmPlayfield, &CPlayField::togglePlayer, ui->lDisplay, &CDisplayLabel::togglePlayer);
    connect(ui->frmPlayfield, &CPlayField::playerScored, ui->lDisplay, &CDisplayLabel::addPoints);
    connect(ui->frmPlayfield, &CPlayField::gameOver, ui->lDisplay, &CDisplayLabel::gameOver);

    connect(ui->pbReset, &QPushButton::clicked, this, &MainWindow::reset);

    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    if (ui->lDisplay->isGameRunning() && QMessageBox::question(0,
                                                               "Spiel läuft",
                                                               "Es läuft bereits ein Spiel. Abbrechen?",
                                                               QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    ui->frmPlayfield->init(ensureEven(ui->sbNumFields->value()));
    ui->lDisplay->reset();
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
