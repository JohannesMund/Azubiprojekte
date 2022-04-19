#pragma once

#include "calculatornumber.h"
#include "result.h"

#include <QMainWindow>

#include "calculator.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_pt_clicked();
    void on_pb_plus_minus_clicked();

    void on_pb_1_clicked();
    void on_pb_2_clicked();
    void on_pb_3_clicked();
    void on_pb_4_clicked();
    void on_pb_5_clicked();
    void on_pb_6_clicked();
    void on_pb_7_clicked();
    void on_pb_8_clicked();
    void on_pb_9_clicked();
    void on_pb_0_clicked();

    void on_pb_op_div_clicked();
    void on_pb_op_mul_clicked();
    void on_pb_op_min_clicked();
    void on_pb_op_plus_clicked();
    void on_pb_op_percent_clicked();
    void on_pb_op_sqrt_clicked();
    void on_pb_op_sq_clicked();

    void on_pb_cmd_enter_clicked();
    void on_pb_cmd_clear_clicked();
    void on_pb_cmd_clearE_clicked();

    void on_pb_cmd_back_clicked();

private:
    Ui::MainWindow* ui;

    void setCurrentResult(const double i);
    void resetCurrentResult();

    Calculator _calc;
};
