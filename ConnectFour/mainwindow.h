#pragma once

#include "cplayermanagement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    void reset();
    void buttonBoxButtonClicked(const unsigned int i);
    CPlayerManagement _playerManagement;
};
