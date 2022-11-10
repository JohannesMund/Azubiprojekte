#include <QCoreApplication>

#include <QTest>

#include "calculatornumber_test.h"
#include "result_test.h"

int main()
{
    int ret = 0;
    CalculatorNumber_Test t1;
    ret |= QTest::qExec(&t1);

    Result_Test t2;
    ret |= QTest::qExec(&t2);

    return ret;
}
