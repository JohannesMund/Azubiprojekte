#pragma once

#include <QObject>
#include <QTest>

class PlayFieldCoords_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_generic();

    void test_invalid_data();

    void test_invalid();
};
