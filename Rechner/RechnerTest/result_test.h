#pragma once

#include <QObject>
#include <QTest>

class Result_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_result_data();
    void test_result();
};
