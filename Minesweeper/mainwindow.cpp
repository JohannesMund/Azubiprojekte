#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cplayfield.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playField->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
