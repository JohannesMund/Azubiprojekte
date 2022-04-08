#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cbModeSelect->insertItem(static_cast<int>(GameMode::pvp), "Mensch");
    ui->cbModeSelect->insertItem(static_cast<int>(GameMode::pvcEasy), "Computer (leicht)");
    ui->cbModeSelect->insertItem(static_cast<int>(GameMode::pvcMedium), "Computer (medium)");
    ui->cbModeSelect->insertItem(static_cast<int>(GameMode::pvcHard), "Computer (schwer)");

    resetGame();

    newTurn();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::buttonPressed( const int x, const int y)
{
    QPushButton *p = getPushButtonAtCoords(x, y);
    if( _grid.setField(PlayField::PlayFieldCoords(x,y),_playerManagement.getCurrentPlayer()) )
    {
        p->setText(_playerManagement.currentPlayerText());

        auto pal = p->palette();
        pal.setColor(QPalette::Normal,QPalette::ButtonText, _playerManagement.currentPlayerColor());
        p->setPalette(pal);

    }

    if( _grid.getGameOver())
    {
        haveWinner(_grid.getWinner());
    }

    newTurn();
}

void MainWindow::newTurn()
{
    _playerManagement.togglePlayer();

    if(_playerManagement.isPlayerTurn())
    {
        ui->lbOut->setText(QString("Spieler %1 ist dran").arg(_playerManagement.currentPlayerName()));
    }
    else
    {

        PlayField::PlayFieldCoords coords;

        if( _currentMode == GameMode::pvcMedium || _currentMode == GameMode::pvcHard)
        {
            coords = _grid.getWinningMove(_playerManagement.getCurrentPlayer());
        }

        if( _currentMode == GameMode::pvcHard && !coords.isValid())
        {
            coords = _grid.getPreventLosingMove(_playerManagement.getCurrentPlayer());
        }

        if( !coords.isValid())
        {
            coords = _grid.getRandomEmptyField();
        }
        buttonPressed(coords.first, coords.second);
    }
}


void MainWindow::haveWinner(const PlayerManagement::Player & p)
{
    if( p == PlayerManagement::Player::none )
    {
        QMessageBox::information(this, "Spielende", QString("Unentschieden"));
    }
    else
    {
        QMessageBox::information(this, "Spielende", QString("Spieler %1 gewinnt").arg(_playerManagement.currentPlayerName()));
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

void MainWindow::setGameMode(const MainWindow::GameMode mode)
{
    ui->lbMode->setText(ui->cbModeSelect->currentText());
    _currentMode = mode;
    _playerManagement.setComputerEnemy(mode != GameMode::pvp);
    newTurn();
}

QPushButton *MainWindow::getPushButtonAtCoords(int x, int y)
{
    if( x == 0)
    {
        if(y == 0) return ui->pb1;
        if(y == 1) return ui->pb2;
        if(y == 2) return ui->pb3;
    }

    if( x == 1)
    {
        if(y == 0) return ui->pb4;
        if(y == 1) return ui->pb5;
        if(y == 2) return ui->pb6;
    }

    if( x == 2)
    {
        if(y == 0) return ui->pb7;
        if(y == 1) return ui->pb8;
        if(y == 2) return ui->pb9;
    }

    assert("das ist kaputt!");
    return 0;
}

void MainWindow::on_pb1_clicked()
{
    buttonPressed(0,0);
}

void MainWindow::on_pb2_clicked()
{
    buttonPressed(0,1);
}

void MainWindow::on_pb3_clicked()
{
    buttonPressed(0,2);
}

void MainWindow::on_pb4_clicked()
{
    buttonPressed(1,0);
}

void MainWindow::on_pb5_clicked()
{
    buttonPressed(1,1);
}

void MainWindow::on_pb6_clicked()
{
    buttonPressed(1,2);
}

void MainWindow::on_pb7_clicked()
{
    buttonPressed(2,0);
}

void MainWindow::on_pb8_clicked()
{
    buttonPressed(2,1);
}

void MainWindow::on_pb9_clicked()
{
    buttonPressed(2,2);
}


void MainWindow::on_cbModeSelect_currentIndexChanged(int index)
{
    resetGame();
    setGameMode(static_cast<GameMode>(index));

}
