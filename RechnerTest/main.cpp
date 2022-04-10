#include <QCoreApplication>

#include <QTest>

#include "calculatornumber_test.h"

int main(int argc, char *argv[])
{

    CalculatorNumber_Test t;
    return QTest::qExec(&t);

}
