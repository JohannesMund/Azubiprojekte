#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_pbReset_clicked();

private:
    static const int _defaultFields;

    Ui::MainWindow* ui;

    void reset();

    static int ensureEven(const int i);
    int getMaxFields() const;
    int getDefaultFields() const;
};
#endif // MAINWINDOW_H
