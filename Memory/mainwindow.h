#pragma once

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

protected:
    void closeEvent(QCloseEvent* e) override;

private:
    Ui::MainWindow* ui;

    void reset();
    void changeGameMode(int i);
    void changeGameMode(const QString& s);

    void fixUpSpinBox();

    int getMaxFields() const;
    int getDefaultFields() const;

    bool askEndGame() const;

    static int ensureEven(const int i);
    static const unsigned int _defaultFields;
};
