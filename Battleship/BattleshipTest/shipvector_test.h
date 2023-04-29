#pragma once

#include "cbattlefieldgrid.h"

#include <QObject>
#include <QTest>

class ShipVector_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_inLine_data();
    void test_inLine();
};
