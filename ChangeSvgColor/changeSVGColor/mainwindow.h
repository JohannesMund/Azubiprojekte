#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "search.h"
#include "change.h"
#include <QMainWindow>
#include <QFileInfoList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_Search_clicked();
    void on_Change_clicked();
    void on_colorPicker_clicked();


private:
    Ui::MainWindow *ui;
    void uiClear();
    void setNewListWidget(QFileInfoList inf);
    void setNewStartColor(std::vector<QString> speicher);
    QFileInfoList fileList;
};
#endif // MAINWINDOW_H
