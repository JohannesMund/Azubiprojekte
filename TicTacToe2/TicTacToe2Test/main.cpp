#include <QCoreApplication>

#include <QTest>

#include "playfield_test.h"
#include "playfieldcoords_test.h"

int main(int argc, char* argv[])
{
    int ret = 0;
    PlayFieldCoords_Test t1;
    ret |= QTest::qExec(&t1);

    PlayField_Test t2;
    ret |= QTest::qExec(&t2);

    return ret;
}
