#pragma once

#include <QObject>
#include <QTest>

class PlayField_Test : public QObject
{
    Q_OBJECT

private slots:

    void test_set_get_data();

    void test_set_get();

    void test_getEmptyFields_data();

    void test_getEmptyFields();

    void test_getWinner_data();

    void test_getWinner();
};
