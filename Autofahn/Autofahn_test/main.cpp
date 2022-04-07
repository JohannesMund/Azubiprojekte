#include "tst_testdrinksfactory.h"
#include "tst_testhansdieter.h"

#include <QTest>

int main()
{

    TestDrinksFactory test1;
    QTest::qExec(&test1);

    TestHansDieter test2;
    QTest::qExec(&test2);

    return 0;


}
