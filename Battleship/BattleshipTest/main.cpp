#include <QCoreApplication>

#include <QTest>

#include "battlefieldgrid_test.h"

int main()
{
    int ret = 0;
    BattleFieldGrid_Test t1;
    ret |= QTest::qExec(&t1);

    return ret;
}
