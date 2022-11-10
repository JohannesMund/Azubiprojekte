#include <QCoreApplication>

#include <QTest>

#include "computerenemy_test.h"
#include "playfield_test.h"
#include "playfieldcoords_test.h"

int main()
{
    int ret = 0;
    PlayFieldCoords_Test t1;
    ret |= QTest::qExec(&t1);

    PlayField_Test t2;
    ret |= QTest::qExec(&t2);

    ComputerEnemy_Test t3;
    ret |= QTest::qExec(&t3);

    return ret;
}
