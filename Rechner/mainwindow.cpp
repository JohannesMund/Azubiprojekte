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

    connect(&_currentNumber,
            &CalculatorNumber::errorOccured,
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

    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPressed(const int i)
{
    _currentNumber << i;
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    QString s = _currentNumber.toString();

    ui->lb_display->setText(s);

    switch (_operator)
    {
    case plus:
        ui->lb_operator->setText("+");
        break;
    case minus:
        ui->lb_operator->setText("-");
        break;
    case multiplication:
        ui->lb_operator->setText("*");
        break;
    case division:
        ui->lb_operator->setText("/");
        break;
    case percent:
        ui->lb_operator->setText("%");
        break;
    case square:
        ui->lb_operator->setText("x²");
        break;
    case squareroot:
        ui->lb_operator->setText("√");
        break;
    case none:
        ui->lb_operator->setText("");
        break;
    }

    if (_currentResult.isValid())
    {
        ui->lb_lastResult->setText(_currentResult.toString());
    }
    else
    {
        ui->lb_lastResult->setNum(0);
    }
}

void MainWindow::on_pb_pt_clicked()
{
    _currentNumber.setCommaPressed(true);
    updateDisplay();
}

void MainWindow::on_pb_plus_minus_clicked()
{
    _currentNumber.toggleNegated();
    updateDisplay();
}

void MainWindow::on_pb_1_clicked()
{
    numberPressed(1);
}

void MainWindow::on_pb_2_clicked()
{
    numberPressed(2);
}

void MainWindow::on_pb_3_clicked()
{
    numberPressed(3);
}

void MainWindow::on_pb_4_clicked()
{
    numberPressed(4);
}

void MainWindow::on_pb_5_clicked()
{
    numberPressed(5);
}

void MainWindow::on_pb_6_clicked()
{
    numberPressed(6);
}

void MainWindow::on_pb_7_clicked()
{
    numberPressed(7);
}

void MainWindow::on_pb_8_clicked()
{
    numberPressed(8);
}

void MainWindow::on_pb_9_clicked()
{
    numberPressed(9);
}

void MainWindow::on_pb_0_clicked()
{
    numberPressed(0);
}

void MainWindow::setOperator(const MainWindow::eOperator op)
{
    calc();
    _operator = op;
    updateDisplay();
}

void MainWindow::on_pb_op_div_clicked()
{
    setOperator(division);
}

void MainWindow::on_pb_op_mul_clicked()
{
    setOperator(multiplication);
}

void MainWindow::on_pb_op_min_clicked()
{
    setOperator(minus);
}

void MainWindow::on_pb_op_plus_clicked()
{
    setOperator(plus);
}

void MainWindow::on_pb_op_percent_clicked()
{
    setOperator(percent);
}

void MainWindow::calc()
{
    if (_currentResult.isValid() == false && _operator != square && _operator != squareroot)
    {
        _currentResult.set(_currentNumber.get());
    }
    else
    {
        double op1 = _currentResult.get();
        double res = 0;

        switch (_operator)
        {
        case plus:
            res = op1 + _currentNumber;
            break;
        case minus:
            res = op1 - _currentNumber;
            break;
        case multiplication:
            res = op1 * _currentNumber;
            break;
        case division:
            res = op1 / _currentNumber;
            break;
        case percent:
            res = op1 * (_currentNumber / 100);
            break;
        case square:
            res = _currentNumber * _currentNumber;
            break;
        case squareroot:
            res = sqrt(_currentNumber);
            break;
        case none:
            res = _currentNumber.get();
            break;
        }

        _currentResult.set(res);
        _currentNumber.set(res);
    }

    _currentNumber.setVolatile();
    updateDisplay();
}

void MainWindow::clearCurrent()
{
    _currentNumber.reset();
    updateDisplay();
}

void MainWindow::clearAll()
{
    _currentResult.reset();
    _operator = none;
    clearCurrent();
}

void MainWindow::on_pb_cmd_enter_clicked()
{
    calc();
}

void MainWindow::on_pb_cmd_clear_clicked()
{
    clearAll();
}

void MainWindow::on_pb_cmd_clearE_clicked()
{
    clearCurrent();
}

void MainWindow::on_pb_cmd_back_clicked()
{
    _currentNumber.removeLast();
    updateDisplay();
}

void MainWindow::on_pb_op_sqrt_clicked()
{
    _operator = squareroot;
    calc();
    updateDisplay();
    _operator = none;
}

void MainWindow::on_pb_op_sq_clicked()
{
    _operator = square;
    calc();
    updateDisplay();
    _operator = none;
}
