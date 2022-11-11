#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->frmButtonBox, &CButtonBox::buttonClicked, this, &MainWindow::buttonBoxButtonClicked);
    connect(ui->pbReset, &QPushButton::clicked, this, &MainWindow::reset);
    _playerManagement.reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonBoxButtonClicked(const unsigned int i)
{
    ui->frmPlayfield->addToColumn(i, _playerManagement.getCurrentPlayer());
    if (ui->frmPlayfield->checkWinner() != CPlayerManagement::Player::none)
    {
        QMessageBox::information(0, "Ende", "Wir haben einen Gewinner!");
    }
    _playerManagement.toggleCurrentPlayer();
    if (ui->frmPlayfield->isColumnFull(i))
    {
        ui->frmButtonBox->deactivateButton(i);
    }
}

void MainWindow::reset()
{
    ui->frmPlayfield->reset();
    ui->frmButtonBox->reset();
}
