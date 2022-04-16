#ifndef PLAYFIELDCOORDS_TEST_H
#define PLAYFIELDCOORDS_TEST_H

#include <QObject>
#include <QTest>

#include "playermanagement.h"
#include "playfield.h"

Q_DECLARE_METATYPE(PlayerManagement::Player)

class PlayField_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_set_get_data()
    {
        QTest::addColumn<int>("x");
        QTest::addColumn<int>("y");
        QTest::addColumn<PlayerManagement::Player>("p");

        QTest::newRow("Test 1") << 0 << 0 << PlayerManagement::Player::plX;
        QTest::newRow("Test 2") << 1 << 1 << PlayerManagement::Player::plO;
        QTest::newRow("Test 3") << 0 << 2 << PlayerManagement::Player::none;

        QTest::newRow("Test 4") << -1 << -1 << PlayerManagement::Player::plX;
        QTest::newRow("Test 5") << -1 << 1 << PlayerManagement::Player::plO;
        QTest::newRow("Test 6") << 0 << INT_MAX << PlayerManagement::Player::none;
    }

    void test_set_get()
    {

        QFETCH(int, x);
        QFETCH(int, y);
        QFETCH(PlayerManagement::Player, p);

        PlayField field;
        PlayFieldCoords coords(x, y);
        QCOMPARE(field.set(coords, p), coords.isValid());

        if (coords.isValid())
        {
            QVERIFY(field.at(coords) == p);
        }
    }
};

#endif // PLAYFIELDCOORDS_TEST_H
