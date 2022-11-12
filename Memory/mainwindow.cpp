#include "mainwindow.h"
#include "cdisplaylabel.h"
#include "cplayfield.h"
#include "cresourcehelper.h"
#include "gamemanagement.h"

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

    for (const QString& s : modes)
    {
        QString text = QString("%1 (%2 Karten)")
                           .arg(CResourceHelper::getInstance()->getResourceName(s))
                           .arg(CResourceHelper::getInstance()->countCards(s));
        ui->cbGameMode->insertItem(0, text, s);
    }

    changeGameMode(modes.first());

    ui->sbNumFields->setMinimum(2);
    ui->sbNumFields->setSingleStep(2);
    ui->sbNumFields->setValue(getDefaultFields());

    connect(ui->cbGameMode,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,
            static_cast<void (MainWindow::*)(int)>(&MainWindow::changeGameMode));

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
