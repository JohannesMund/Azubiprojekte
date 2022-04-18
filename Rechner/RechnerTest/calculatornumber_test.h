#pragma once

#include <QObject>
#include <QTest>

class CalculatorNumber_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_addDigit_data();
    void test_addDigit();

    void test_getAndSet_data();
    void test_getAndSet();

    void test_add_data();
    void test_add();

    void test_sub_data();
    void test_sub();

    void test_mul_data();
    void test_mul();

    void test_div_data();
    void test_div();

    void test_sqrt_data();
    void test_sqrt();

    void test_sq_data();
    void test_sq();
};
