#pragme once

#include <QObject>
#include <QTest>

#include "result.h"

class Result_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_addDigit_data()
    {
        QTest::addColumn<double>("in");
        QTest::addColumn<QString>("asString");

        QTest::newRow("Test1") << 12345.0 << "12345";
        QTest::newRow("Test2") << 12345.6789 << "12345.6789";
        QTest::newRow("Test3") << -12345.6789 << "-12345.6789";
        QTest::newRow("Test4") << -12345.6789000000000000000001 << "-12345.6789";
        QTest::newRow("Test5") << 12345.6789000000000000000001 << "12345.6789";
    }

    void test_addDigit()
    {
        Result r;
        QVERIFY(!r.isValid());

        QFETCH(double, in);
        r.set(in);

        QVERIFY(r.isValid());
        QCOMPARE(r.get(), in);

        QFETCH(QString, asString);
        QCOMPARE(r.toString(), asString);
    }
};
