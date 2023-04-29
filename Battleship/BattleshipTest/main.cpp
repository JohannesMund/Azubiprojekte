#include <QCoreApplication>

#include <QTest>

#include "battlefieldgrid_test.h"
#include "shipvector_test.h"

int main()
{
    int ret = 0;
    BattleFieldGrid_Test t1;
    ret |= QTest::qExec(&t1);

    ShipVector_Test t2;
    ret |= QTest::qExec(&t2);

    return ret;
}
