#ifndef CALCULATORNUMBER_TEST_H
#define CALCULATORNUMBER_TEST_H

#include <QObject>
#include <QTest>

#include "calculatornumber.h"


class CalculatorNumber_Test : public QObject
{
    Q_OBJECT


private slots:



    void test_addDigit_data()
    {
        QTest::addColumn<QVector<int>>("in");
        QTest::addColumn<double>("res");

        QVector<int> v;
        v << 1 << 2 << 3 << 4 << 5;
        QTest::newRow("Test1") <<  v << 12345.0;

        v.clear();
        v << 1 << 2 << 3 << 4 << 5 << ',' << 6 << 7 << 8 << 9;
        QTest::newRow("Test2") <<  v << 12345.6789;

        v.clear();
        v << '-' << 1 << 2 << 3 << 4 << 5 << ',' << 6 << 7 << 8 << 9;
        QTest::newRow("Test3") <<  v << -12345.6789;
    }

    void test_addDigit()
    {
        QFETCH(QVector<int>, in);
        QFETCH(double, res);

        CalculatorNumber n;
        for(auto i : in)
        {
            if(i == ',')
                n.setCommaPressed(true);
            else if( i == '-')
                n.toggleNegated();
            else
                n.addDigit(i);
        }
        QCOMPARE(n.get(),res);
    }


    void test_getAndSet_data()
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

    void test_getAndSet()
    {
        QFETCH(double, in);
        CalculatorNumber n;
        n.set(in);
        QCOMPARE(n.get(), in);
    }


};

#endif // CALCULATORNUMBER_TEST_H
