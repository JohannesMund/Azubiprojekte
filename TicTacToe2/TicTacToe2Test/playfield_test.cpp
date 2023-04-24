#include "playfield_test.h"

#include "playermanagement.h"
#include "playfield.h"
#include "testdefines.h"

void PlayField_Test::test_set_get_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<PlayerManagement::Player>("p");

    QTest::newRow("Test X 1") << 0 << 0 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 2") << 0 << 1 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 3") << 0 << 2 << PlayerManagement::Player::plX;

    QTest::newRow("Test X 4") << 1 << 0 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 5") << 1 << 1 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 6") << 1 << 2 << PlayerManagement::Player::plX;

    QTest::newRow("Test X 7") << 2 << 0 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 8") << 2 << 1 << PlayerManagement::Player::plX;
    QTest::newRow("Test X 9") << 2 << 2 << PlayerManagement::Player::plX;

    QTest::newRow("Test O 1") << 0 << 0 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 0 << 1 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 0 << 2 << PlayerManagement::Player::plO;

    QTest::newRow("Test O 1") << 1 << 0 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 1 << 1 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 1 << 2 << PlayerManagement::Player::plO;

    QTest::newRow("Test O 1") << 2 << 0 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 2 << 1 << PlayerManagement::Player::plO;
    QTest::newRow("Test O 1") << 2 << 2 << PlayerManagement::Player::plO;

    QTest::newRow("Test No Player 1") << 0 << 0 << PlayerManagement::Player::none;
    QTest::newRow("Test No Player 2") << 1 << 1 << PlayerManagement::Player::none;
    QTest::newRow("Test No Player 3") << 2 << 2 << PlayerManagement::Player::none;

    QTest::newRow("Test Invalid 1") << -1 << -1 << PlayerManagement::Player::plX;
    QTest::newRow("Test Invalid 2") << -1 << 1 << PlayerManagement::Player::plO;
    QTest::newRow("Test Invalid 3") << 1 << -1 << PlayerManagement::Player::plO;

    QTest::newRow("Test Invalid 4") << 0 << INT_MAX << PlayerManagement::Player::plO;
    QTest::newRow("Test Invalid 5") << INT_MAX << 0 << PlayerManagement::Player::plX;
    QTest::newRow("Test Invalid 6") << INT_MAX << INT_MAX << PlayerManagement::Player::plO;

    QTest::newRow("Test Invalid 7") << 0 << INT_MIN << PlayerManagement::Player::plX;
    QTest::newRow("Test Invalid 8") << INT_MIN << 0 << PlayerManagement::Player::plO;
    QTest::newRow("Test Invalid 9") << INT_MIN << INT_MIN << PlayerManagement::Player::plX;

    QTest::newRow("Test Invalid 10") << INT_MIN << INT_MAX << PlayerManagement::Player::plO;
    QTest::newRow("Test Invalid 11") << INT_MAX << INT_MIN << PlayerManagement::Player::plX;
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
    else
    {
        QVERIFY(field.at(coords) == PlayerManagement::Player::none);
    }
}

void PlayField_Test::test_getEmptyFields_data()
{
    QTest::addColumn<QVector<PlayFieldCoords>>("coords");

    QTest::newRow("Test1") << QVector<PlayFieldCoords>({{0, 0}});
    QTest::newRow("Test2") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}});
    QTest::newRow("Test3") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}});
    QTest::newRow("Test4") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}, {0, 1}});
    QTest::newRow("Test5") << QVector<PlayFieldCoords>({{0, 0}, {1, 1}, {2, 2}, {1, 0}});
    QTest::newRow("Test6") << QVector<PlayFieldCoords>(
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}});
    QTest::newRow("Test7") << QVector<PlayFieldCoords>(
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}});
    QTest::newRow("Test8") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}});
    QTest::newRow("Test9") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}});
    QTest::newRow("Test10") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}});
    QTest::newRow("Test11") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}, {0, 2}, {1, 0}});
    QTest::newRow("Test12") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}, {0, 2}});
    QTest::newRow("Test13") << QVector<PlayFieldCoords>({{0, 0}, {0, 1}});
}

void PlayField_Test::test_getEmptyFields()
{
    QFETCH(QVector<PlayFieldCoords>, coords);
    PlayField p;
    for (const auto& c : coords)
    {
        p.set(c, PlayerManagement::Player::plX);
    }

    const auto emptyFields = p.getEmptyFields();
    QCOMPARE(emptyFields.size(), (9 - coords.size()));

    for (const auto& f : emptyFields)
    {
        QVERIFY(p.at(f) == PlayerManagement::Player::none);
    }
}

void PlayField_Test::test_getWinner_data()
{
    QTest::addColumn<PlayFieldRepresentation>("fieldRep");
    QTest::addColumn<PlayerManagement::Player>("winner");

    QTest::newRow("kein Gewinner 1") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX}})
                                     << PlayerManagement::Player::none;
    QTest::newRow("kein Gewinner 2") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                                 {{1, 0}, PlayerManagement::Player::plO}})
                                     << PlayerManagement::Player::none;

    QTest::newRow("kein Gewinner 3") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                                 {{1, 0}, PlayerManagement::Player::plO},
                                                                 {{0, 1}, PlayerManagement::Player::plX}})
                                     << PlayerManagement::Player::none;
    QTest::newRow("Diagonal X") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                            {{1, 1}, PlayerManagement::Player::plX},
                                                            {{2, 2}, PlayerManagement::Player::plX},

                                                            {{0, 1}, PlayerManagement::Player::plO},
                                                            {{0, 2}, PlayerManagement::Player::plO},
                                                            {{1, 2}, PlayerManagement::Player::plO}})
                                << PlayerManagement::Player::plX;
    QTest::newRow("Diagonal O") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                            {{2, 1}, PlayerManagement::Player::plX},
                                                            {{1, 2}, PlayerManagement::Player::plX},

                                                            {{2, 0}, PlayerManagement::Player::plO},
                                                            {{1, 1}, PlayerManagement::Player::plO},
                                                            {{0, 2}, PlayerManagement::Player::plO}})
                                << PlayerManagement::Player::plO;
    QTest::newRow("Senkrecht X") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
                                                             {{0, 1}, PlayerManagement::Player::plX},
                                                             {{0, 2}, PlayerManagement::Player::plX},

                                                             {{1, 1}, PlayerManagement::Player::plO},
                                                             {{1, 2}, PlayerManagement::Player::plO},
                                                             {{2, 1}, PlayerManagement::Player::plO}})
                                 << PlayerManagement::Player::plX;
    QTest::newRow("Senkrecht O") << PlayFieldRepresentation({{{1, 0}, PlayerManagement::Player::plX},
                                                             {{1, 1}, PlayerManagement::Player::plX},
                                                             {{2, 2}, PlayerManagement::Player::plX},

                                                             {{0, 0}, PlayerManagement::Player::plO},
                                                             {{0, 1}, PlayerManagement::Player::plO},
                                                             {{0, 2}, PlayerManagement::Player::plO}})
                                 << PlayerManagement::Player::plO;
    QTest::newRow("Waagerecht X") << PlayFieldRepresentation({{{1, 0}, PlayerManagement::Player::plX},
                                                              {{2, 0}, PlayerManagement::Player::plX},
                                                              {{0, 0}, PlayerManagement::Player::plX},

                                                              {{0, 2}, PlayerManagement::Player::plO},
                                                              {{1, 1}, PlayerManagement::Player::plO},
                                                              {{2, 2}, PlayerManagement::Player::plO}})
                                  << PlayerManagement::Player::plX;
    QTest::newRow("Waagerecht O") << PlayFieldRepresentation({{{0, 0}, PlayerManagement::Player::plX},
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
