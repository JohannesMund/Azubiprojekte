#include "mainwindow.h"
#include "cdisplaylabel.h"
#include "cplayfield.h"
#include "cresourcehelper.h"
#include "gamemanagement.h"

#include <QCloseEvent>
#include <QComboBox>
#include <QMessageBox>

#include "ui_mainwindow.h"

const unsigned int MainWindow::_defaultFields = 36;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frmDisplay->reset();

    connect(ui->frmPlayfield, &CPlayField::togglePlayer, &GameManagement::toggleCurrentPlayer);
    connect(ui->frmPlayfield, &CPlayField::playerScored, &GameManagement::startGame);
    connect(ui->frmPlayfield, &CPlayField::gameOver, &GameManagement::stopGame);

    connect(ui->frmPlayfield, &CPlayField::togglePlayer, ui->frmDisplay, &CDisplayLabel::togglePlayer);
    connect(ui->frmPlayfield, &CPlayField::playerScored, ui->frmDisplay, &CDisplayLabel::addPoints);
    connect(ui->frmPlayfield, &CPlayField::gameOver, ui->frmDisplay, &CDisplayLabel::gameOver);

    connect(ui->pbReset, &QPushButton::clicked, this, &MainWindow::reset);

    const auto modes = CResourceHelper::getInstance()->getRecourceDirectories();

    ui->cbGameMode->setIconSize(QSize(32, 32));
    for (const QString& s : modes)
    {

        QString text = QString("%1 (%2 Bilder)")
                           .arg(CResourceHelper::getInstance()->getResourceName(s))
                           .arg(CResourceHelper::getInstance()->countCards(s));
        ui->cbGameMode->insertItem(0, QIcon(CResourceHelper::getInstance()->getRecourceFileName(1, s)), text, s);
    }

    changeGameMode(modes.first());

    connect(ui->cbGameMode,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,
            static_cast<void (MainWindow::*)(int)>(&MainWindow::changeGameMode));

    ui->sbNumFields->setMinimum(2);
    ui->sbNumFields->setSingleStep(2);
    ui->sbNumFields->setValue(getDefaultFields());
    connect(ui->sbNumFields, &QSpinBox::editingFinished, this, &MainWindow::fixUpSpinBox);

    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* e)
{
    if (askEndGame() == false)
    {
        e->ignore();
        return;
    }
    QMainWindow::closeEvent(e);
}

void MainWindow::reset()
{
    if (askEndGame() == false)
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
        return i - 1;
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

bool MainWindow::askEndGame() const
{
    if (GameManagement::isGameRunning() && QMessageBox::question(0,
                                                                 "Spiel läuft",
                                                                 "Es läuft bereits ein Spiel. Abbrechen?",
                                                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return false;
    }
    return true;
}

void MainWindow::changeGameMode(int i)
{
    auto mode = ui->cbGameMode->itemData(i).toString();
    changeGameMode(mode);
}

void MainWindow::changeGameMode(const QString& mode)
{
    CResourceHelper::getInstance()->setGameMode(mode);
    ui->sbNumFields->setMaximum(getMaxFields());
}

void MainWindow::fixUpSpinBox()
{
    ui->sbNumFields->setValue(ensureEven(ui->sbNumFields->value()));
}
