#include "mainwindow.h"
#include "cdisplaylabel.h"
#include "cplayfield.h"

#include "ui_mainwindow.h"

const int MainWindow::_defaultFields = 36;

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

    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
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
    return ensureEven(CPlayField::_maxFields);
}

int MainWindow::getDefaultFields() const
{
    return ensureEven(_defaultFields);
}

void MainWindow::on_pbReset_clicked()
{
    reset();
}
