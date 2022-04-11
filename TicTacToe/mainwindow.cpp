#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resetGame();

    newTurn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonPressed(QPushButton* p, const int x, const int y)
{
    if (_grid.setField(x, y, _playerManagement.getCurrentPlayer())) {
        p->setText(_playerManagement.currentPlayerText());

        auto pal = p->palette();
        pal.setColor(QPalette::Normal, QPalette::ButtonText,
            _playerManagement.currentPlayerColor());
        p->setPalette(pal);
    }

    if (_grid.gameOver()) {
        haveWinner(_grid.winner());
    }

    newTurn();
}

void MainWindow::newTurn()
{
    _playerManagement.togglePlayer();
    ui->lbOut->setText(QString("Spieler %1 ist dran")
                           .arg(_playerManagement.currentPlayerText()));
}

void MainWindow::haveWinner(const PlayerManagement::Player& p)
{
    if (p == PlayerManagement::none) {
        QMessageBox::information(this, "Spielende", QString("Unentschieden"));
    } else {
        QMessageBox::information(
            this, "Spielende",
            QString("Spieler %1 gewinnt").arg(PlayerManagement::playerToText(p)));
    }

    resetGame();
}

void MainWindow::resetGame()
{
    ui->pb1->setText("");
    ui->pb2->setText("");
    ui->pb3->setText("");
    ui->pb4->setText("");
    ui->pb5->setText("");
    ui->pb6->setText("");
    ui->pb7->setText("");
    ui->pb8->setText("");
    ui->pb9->setText("");

    _grid.reset();
}

void MainWindow::on_pb1_clicked() { buttonPressed(ui->pb1, 0, 0); }

void MainWindow::on_pb2_clicked() { buttonPressed(ui->pb2, 0, 1); }

void MainWindow::on_pb3_clicked() { buttonPressed(ui->pb3, 0, 2); }

void MainWindow::on_pb4_clicked() { buttonPressed(ui->pb4, 1, 0); }

void MainWindow::on_pb5_clicked() { buttonPressed(ui->pb5, 1, 1); }

void MainWindow::on_pb6_clicked() { buttonPressed(ui->pb6, 1, 2); }

void MainWindow::on_pb7_clicked() { buttonPressed(ui->pb7, 2, 0); }

void MainWindow::on_pb8_clicked() { buttonPressed(ui->pb8, 2, 1); }

void MainWindow::on_pb9_clicked() { buttonPressed(ui->pb9, 2, 2); }
