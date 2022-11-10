#include "calculatornumber_test.h"

#include "calculatornumber.h"

void CalculatorNumber_Test::test_addDigit_data()
{
    QTest::addColumn<QVector<int>>("in");
    QTest::addColumn<double>("res");

    QVector<int> v;
    v << 1 << 2 << 3 << 4 << 5;
    QTest::newRow("Test1") << v << 12345.0;

    v.clear();
    v << 1 << 2 << 3 << 4 << 5 << ',' << 6 << 7 << 8 << 9;
    QTest::newRow("Test2") << v << 12345.6789;

    v.clear();
    v << '-' << 1 << 2 << 3 << 4 << 5 << ',' << 6 << 7 << 8 << 9;
    QTest::newRow("Test3") << v << -12345.6789;
}

void CalculatorNumber_Test::test_addDigit()
{
    QFETCH(QVector<int>, in);
    QFETCH(double, res);

    CalculatorNumber n1;
    CalculatorNumber n2;
    for (auto i : in)
    {
        if (i == ',')
        {
            n1.setCommaPressed(true);
            n2 << '.';
        }
        else if (i == '-')
        {
            n1.toggleNegated();
            n2 << '-';
        }
        else
        {
            n1.addDigit(i);
            n2 << i;
        }
    }
    QCOMPARE(n1.get(), res);
    QCOMPARE(n2.get(), res);
}

void CalculatorNumber_Test::test_getAndSet_data()
{
    QTest::addColumn<double>("in");

    QTest::newRow("Test1") << 1.0;
    QTest::newRow("Test2") << 12345.12345;
    QTest::newRow("Test3") << -1.0;
    QTest::newRow("Test4") << -12345.23456;
    QTest::newRow("Test5") << 99.0;
    QTest::newRow("Test6") << -99.0;
    QTest::newRow("Test7") << 1.0000001;
    QTest::newRow("Test8") << 0.0000001;
    QTest::newRow("Test9") << 99.0050001;
    QTest::newRow("Test10") << -1.0000021;
}

void CalculatorNumber_Test::test_getAndSet()
{
    QFETCH(double, in);
    CalculatorNumber n;
    n.set(in);
    QCOMPARE(n.get(), in);
}

void CalculatorNumber_Test::test_add_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("op2");
    QTest::addColumn<double>("res");

    QTest::newRow("Test Add 1") << 1.0 << 1.0 << 2.0;
    QTest::newRow("Test Add 2") << 1.0 << -1.0 << 0.0;
    QTest::newRow("Test Add 3") << -1.0 << 1.0 << 0.0;

    QTest::newRow("Test Add 4") << 1.000001 << 1.0 << 2.000001;
    QTest::newRow("Test Add 5") << 12345.0 << 0.12345 << 12345.12345;
    QTest::newRow("Test Add 6") << 12345.12345 << 12345.12345 << 24690.2469;
}

void CalculatorNumber_Test::test_add()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, op2);
    CalculatorNumber o2;
    o2.set(op2);

    QFETCH(double, res);

    o1 = o1 + o2;
    QCOMPARE(o1.get(), res);
}

void CalculatorNumber_Test::test_sub_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("op2");
    QTest::addColumn<double>("res");

    QTest::newRow("Test Sub 1") << 1.0 << 1.0 << 0.0;
    QTest::newRow("Test Sub 2") << 1.0 << -1.0 << 2.0;
    QTest::newRow("Test Sub 3") << -1.0 << 1.0 << -2.0;

    QTest::newRow("Test Sub 4") << 1.00001 << 1.0 << 0.00001;
    QTest::newRow("Test Sub 5") << 12345.0 << 0.12345 << 12344.87655;
    QTest::newRow("Test Sub 6") << 12345.12345 << 12345.12345 << 0.0;
}

void CalculatorNumber_Test::test_sub()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, op2);
    CalculatorNumber o2;
    o2.set(op2);

    QFETCH(double, res);

    o1 = o1 - o2;
    QCOMPARE(o1.get(), res);
}

void CalculatorNumber_Test::test_mul_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("op2");
    QTest::addColumn<double>("res");

    QTest::newRow("Test Mul 1") << 1.0 << 1.0 << 1.0;
    QTest::newRow("Test Mul 2") << 1.0 << -1.0 << -1.0;
    QTest::newRow("Test Mul 3") << -1.0 << 1.0 << -1.0;

    QTest::newRow("Test Mul 4") << 1.00001 << 1.0 << 1.00001;
    QTest::newRow("Test Mul 5") << 12345.0 << 0.12345 << 1523.99025;
    QTest::newRow("Test Mul 6") << 12345.0 << 12345.0 << 152399025.0;
}

void CalculatorNumber_Test::test_mul()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, op2);
    CalculatorNumber o2;
    o2.set(op2);

    QFETCH(double, res);

    o1 = o1 * o2;
    QCOMPARE(o1.get(), res);
}

void CalculatorNumber_Test::test_div_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("op2");
    QTest::addColumn<double>("res");

    QTest::newRow("Test Div 1") << 1.0 << 1.0 << 1.0;
    QTest::newRow("Test Div 2") << 1.0 << -1.0 << -1.0;
    QTest::newRow("Test Mul 3") << -1.0 << 1.0 << -1.0;

    QTest::newRow("Test Div 4") << 1.00001 << 1.0 << 1.00001;
    QTest::newRow("Test Div 5") << 12345.0 << 0.12345 << 100000.0;
    QTest::newRow("Test Div 6") << 12345.0 << 12345.0 << 1.0;
}

void CalculatorNumber_Test::test_div()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, op2);
    CalculatorNumber o2;
    o2.set(op2);

    QFETCH(double, res);

    o1 = o1 / o2;
    QCOMPARE(o1.get(), res);
}

void CalculatorNumber_Test::test_sqrt_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("res");

    QTest::newRow("Test sqrt 1") << 9.0 << 3.0;
    QTest::newRow("Test sqrt 2") << 4.0 << 2.0;
    QTest::newRow("Test sqrt 3") << 100.0 << 10.0;
    QTest::newRow("Test sqrt 4") << -1.0 << 0.0;
    QTest::newRow("Test sqrt 5") << 0.0 << 0.0;
}

void CalculatorNumber_Test::test_sqrt()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, res);

    o1 = sqrt(o1);
    QCOMPARE(o1.get(), res);
}

void CalculatorNumber_Test::test_sq_data()
{
    QTest::addColumn<double>("op1");
    QTest::addColumn<double>("res");

    QTest::newRow("Test sqrt 1") << 9.0 << 81.0;
    QTest::newRow("Test sqrt 2") << 4.0 << 16.0;
    QTest::newRow("Test sqrt 3") << 100.0 << 10000.0;
    QTest::newRow("Test sqrt 4") << -1.0 << 1.0;
    QTest::newRow("Test sqrt 5") << 0.0 << 0.0;
}

void CalculatorNumber_Test::test_sq()
{
    QFETCH(double, op1);
    CalculatorNumber o1;
    o1.set(op1);

    QFETCH(double, res);

    o1 = o1 * o1;
    QCOMPARE(o1.get(), res);
}
