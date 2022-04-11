#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

#include "playermanagement.h"
#include "playfield.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
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
  enum class GameMode { pvp = 0, pvcEasy = 1, pvcMedium = 2, pvcHard = 3 };

  Ui::MainWindow *ui;

  PlayerManagement _playerManagement;
  PlayField _grid;

  void buttonPressed(const int x, const int y);
  void newTurn();

  void haveWinner(const PlayerManagement::Player &);
  void resetGame();

  void setGameMode(const GameMode mode);

  QPushButton *getPushButtonAtCoords(int x, int y);

  GameMode _currentMode;
};

#endif // MAINWINDOW_H
