#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    void initMenu();

    QActionGroup* _playFieldSizeActions;
    QActionGroup* _bombCountActions;

    void newGame();

private slots:
    void resizeEvent(QResizeEvent* e);
};
