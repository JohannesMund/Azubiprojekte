#pragma once

#include <QObject>
#include <QTest>

class PlayField;
class ComputerEnemy;
struct PlayFieldCoords;

class ComputerEnemy_Test : public QObject
{
    Q_OBJECT

private:
    void checkMoveIsValid(const PlayField& playfield, const PlayFieldCoords& coords);
    void doTheMove(const ComputerEnemy& c);

    void makeColumns();

    void easyData();
    void mediumData();
    void hardData();
    void insaneData();

private slots:
    void test_doMove_easy_data();
    void test_doMove_easy();

    void test_doMove_medium_data();
    void test_doMove_medium();

    void test_doMove_hard_data();
    void test_doMove_hard();

    void test_doMove_insane_data();
    void test_doMove_insane();
};
