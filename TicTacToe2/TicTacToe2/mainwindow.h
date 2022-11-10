#pragma once

#include <QMainWindow>
#include <qpushbutton.h>

#include "computerenemy.h"
#include "playermanagement.h"
#include "playfield.h"

namespace Ui
{
class MainWindow;
}
struct PlayFieldCoords;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb1_clicked();
    void on_pb2_clicked();
    void on_pb3_clicked();
    void on_pb4_clicked();
    void on_pb5_clicked();
    void on_pb6_clicked();
    void on_pb7_clicked();
    void on_pb8_clicked();
    void on_pb9_clicked();

    void on_cbModeSelect_currentIndexChanged(int index);

private:
    static constexpr int gameModePvP = 0;

    Ui::MainWindow* ui;

    PlayerManagement _playerManagement;
    PlayField _grid;
    ComputerEnemy _enemy;

    void buttonPressed(const int x, const int y);
    void buttonPressed(const PlayFieldCoords& coords);
    void newTurn();

    void haveWinner(const PlayerManagement::Player&);
    void resetGame();

    QPushButton* getPushButtonAtCoords(const int x, const int y);
};
