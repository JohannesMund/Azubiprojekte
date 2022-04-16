#ifndef PLAYFIELD_TEST_H
#define PLAYFIELD_TEST_H

#include <QObject>
#include <QTest>

#include "playfieldcoords.h"

class PlayFieldCoords_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_generic()
    {
        PlayFieldCoords coords;
        QVERIFY(!coords.isValid());
        QVERIFY(coords.x() == -1);
        QVERIFY(coords.y() == -1);

        coords.first = 1;
        coords.second = 2;

        QVERIFY(coords.isValid());
        QVERIFY(coords.x() == 1);
        QVERIFY(coords.y() == 2);

        coords.first = -1;
        QVERIFY(!coords.isValid());
        QVERIFY(coords.x() == -1);
        QVERIFY(coords.y() == 2);

        PlayFieldCoords coords2(1, 2);
        QVERIFY(coords2.isValid());
        QVERIFY(coords2.x() == 1);
        QVERIFY(coords2.y() == 2);
    }

    void test_invalid_data()
    {
        QTest::addColumn<int>("x");
        QTest::addColumn<int>("y");
        QTest::addColumn<bool>("valid");

        QTest::newRow("Test valid 1") << 0 << 0 << true;
        QTest::newRow("Test valid 2") << 1 << 1 << true;
        QTest::newRow("Test valid 3") << 2 << 2 << true;

        QTest::newRow("Test valid 4") << 0 << 2 << true;
        QTest::newRow("Test valid 5") << 1 << 1 << true;
        QTest::newRow("Test valid 6") << 2 << 0 << true;

        QTest::newRow("Test invalid 1") << -1 << -1 << false;
        QTest::newRow("Test invalid 2") << 3 << 3 << false;
        QTest::newRow("Test invalid 3") << -1 << 1 << false;
        QTest::newRow("Test invalid 4") << 1 << 3 << false;
        QTest::newRow("Test invalid 5") << -99 << -99 << false;
        QTest::newRow("Test invalid 6") << INT_MAX << INT_MIN << false;
    }

    void test_invalid()
    {
        QFETCH(int, x);
        QFETCH(int, y);
        QFETCH(bool, valid);

        PlayFieldCoords coords(x, y);
        QCOMPARE(coords.isValid(), valid);
    }
};

#endif // COORDS_TEST_H
