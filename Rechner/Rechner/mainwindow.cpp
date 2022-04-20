#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pb_0->setShortcut(QKeySequence(Qt::Key_0));
    ui->pb_1->setShortcut(QKeySequence(Qt::Key_1));
    ui->pb_2->setShortcut(QKeySequence(Qt::Key_2));

    ui->pb_3->setShortcut(QKeySequence(Qt::Key_3));
    ui->pb_4->setShortcut(QKeySequence(Qt::Key_4));
    ui->pb_5->setShortcut(QKeySequence(Qt::Key_5));
    ui->pb_6->setShortcut(QKeySequence(Qt::Key_6));
    ui->pb_7->setShortcut(QKeySequence(Qt::Key_7));
    ui->pb_8->setShortcut(QKeySequence(Qt::Key_8));
    ui->pb_9->setShortcut(QKeySequence(Qt::Key_9));

    ui->pb_pt->setShortcut(QKeySequence(Qt::Key_Comma));

    ui->pb_cmd_enter->setShortcut(QKeySequence(Qt::Key_Enter));
    ui->pb_cmd_back->setShortcut(QKeySequence(Qt::Key_Backspace));

    ui->pb_op_div->setShortcut(QKeySequence(Qt::Key_Slash));
    ui->pb_op_min->setShortcut(QKeySequence(Qt::Key_Minus));
    ui->pb_op_mul->setShortcut(QKeySequence(Qt::Key_Asterisk));
    ui->pb_op_plus->setShortcut(QKeySequence(Qt::Key_Plus));

    connect(&_calc,
            &Calculator::errorOccured,
            this,
            [&](const bool b)
            {
                if (b)
                {
                    ui->lb_ErrorDisplay->setText("ERR");
                }
                else
                {
                    ui->lb_ErrorDisplay->setText("");
                }
            });

    connect(&_calc, &Calculator::numberUpdated, this, [&](const QString& number) { ui->lb_display->setText(number); });

    connect(
        &_calc, &Calculator::resultUpdated, this, [&](const QString& number) { ui->lb_lastResult->setText(number); });

    connect(&_calc, &Calculator::operatorUpdated, this, [&](const QString& op) { ui->lb_operator->setText(op); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_pt_clicked()
{
    _calc.commaPressed();
}

void MainWindow::on_pb_plus_minus_clicked()
{
    _calc.negatedPressed();
}

void MainWindow::on_pb_1_clicked()
{
    _calc.numberPressed(1);
}

void MainWindow::on_pb_2_clicked()
{
    _calc.numberPressed(2);
}

void MainWindow::on_pb_3_clicked()
{
    _calc.numberPressed(3);
}

void MainWindow::on_pb_4_clicked()
{
    _calc.numberPressed(4);
}

void MainWindow::on_pb_5_clicked()
{
    _calc.numberPressed(5);
}

void MainWindow::on_pb_6_clicked()
{
    _calc.numberPressed(6);
}

void MainWindow::on_pb_7_clicked()
{
    _calc.numberPressed(7);
}

void MainWindow::on_pb_8_clicked()
{
    _calc.numberPressed(8);
}

void MainWindow::on_pb_9_clicked()
{
    _calc.numberPressed(9);
}

void MainWindow::on_pb_0_clicked()
{
    _calc.numberPressed(0);
}

void MainWindow::on_pb_op_div_clicked()
{
    _calc.setOperator(Calculator::Operator::division);
}

void MainWindow::on_pb_op_mul_clicked()
{
    _calc.setOperator(Calculator::Operator::multiplication);
}

void MainWindow::on_pb_op_min_clicked()
{
    _calc.setOperator(Calculator::Operator::minus);
}

void MainWindow::on_pb_op_plus_clicked()
{
    _calc.setOperator(Calculator::Operator::plus);
}

void MainWindow::on_pb_op_percent_clicked()
{
    _calc.setOperator(Calculator::Operator::percent);
}

void MainWindow::on_pb_cmd_enter_clicked()
{
    _calc.calc();
}

void MainWindow::on_pb_cmd_clear_clicked()
{
    _calc.clearAll();
}

void MainWindow::on_pb_cmd_clearE_clicked()
{
    _calc.clearCurrent();
}

void MainWindow::on_pb_cmd_back_clicked()
{
    _calc.removeLast();
}

void MainWindow::on_pb_op_sqrt_clicked()
{
    _calc.setOperator(Calculator::Operator::squareroot);
}

void MainWindow::on_pb_op_sq_clicked()
{
    _calc.setOperator(Calculator::Operator::square);
}
