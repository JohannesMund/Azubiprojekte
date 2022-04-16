#include "playfield_test.h"

#include "playermanagement.h"
#include "playfield.h"
#include "testdefines.h"

void PlayField_Test::test_set_get_data()
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

void PlayField_Test::test_set_get()
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

void PlayField_Test::test_getEmptyFields_data()
{
    QTest::addColumn<QVector<PlayFieldCoords>>("coords");

    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}});
    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}});
    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}});
    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}, {0, 1}});
    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}, {1, 0}});
}

void PlayField_Test::test_getEmptyFields()
{
    QFETCH(QVector<PlayFieldCoords>, coords);
    PlayField p;
    for (const auto c : coords)
    {
        p.set(c, PlayerManagement::Player::plX);
    }

    const auto emptyFields = p.getEmptyFields();
    QCOMPARE(emptyFields.size(), (9 - coords.size()));

    for (const auto f : emptyFields)
    {
        QVERIFY(p.at(f) == PlayerManagement::Player::none);
    }
}

void PlayField_Test::test_getWinner_data()
{
    QTest::addColumn<PlayFieldRepresentation>("fieldRep");
    QTest::addColumn<PlayerManagement::Player>("winner");

    QTest::newRow("Test1") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX}})
                           << PlayerManagement::Player::none;
    QTest::newRow("Test2") << PlayFieldRepresentation(
                                  {{{0, 0}, PlayerManagement::Player::plX}, {{1, 0}, PlayerManagement::Player::plO}})
                           << PlayerManagement::Player::none;

    QTest::newRow("Test3") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                       {{1, 0}, PlayerManagement::Player::plO},
                                                       {{0, 1}, PlayerManagement::Player::plX}})
                           << PlayerManagement::Player::none;
    QTest::newRow("Test3") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                       {{1, 1}, PlayerManagement::Player::plX},
                                                       {{2, 2}, PlayerManagement::Player::plX},

                                                       {{0, 1}, PlayerManagement::Player::plO},
                                                       {{0, 2}, PlayerManagement::Player::plO},
                                                       {{1, 2}, PlayerManagement::Player::plO}})
                           << PlayerManagement::Player::plX;
    QTest::newRow("Test4") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                       {{0, 1}, PlayerManagement::Player::plX},
                                                       {{0, 2}, PlayerManagement::Player::plX},

                                                       {{1, 1}, PlayerManagement::Player::plO},
                                                       {{1, 2}, PlayerManagement::Player::plO},
                                                       {{2, 1}, PlayerManagement::Player::plO}})
                           << PlayerManagement::Player::plX;
    QTest::newRow("Test4") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                       {{1, 0}, PlayerManagement::Player::plX},
                                                       {{0, 1}, PlayerManagement::Player::plX},

                                                       {{0, 2}, PlayerManagement::Player::plO},
                                                       {{1, 2}, PlayerManagement::Player::plO},
                                                       {{2, 2}, PlayerManagement::Player::plO}})
                           << PlayerManagement::Player::plO;
}

void PlayField_Test::test_getWinner()
{
    QFETCH(PlayFieldRepresentation, fieldRep);

    const auto field = populatePlayField(fieldRep);

    QFETCH(PlayerManagement::Player, winner);

    if ((winner != PlayerManagement::Player::none))
    {
        QCOMPARE(winner, field.getWinner());
        QVERIFY(field.getGameOver());
    }
    else
    {
        QVERIFY(!field.getGameOver());
    }
}
