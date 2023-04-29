#pragma once

#include "cbattlefieldgrid.h"

#include <QObject>
#include <QTest>

using TestGrid = std::vector<std::vector<int>>;
Q_DECLARE_METATYPE(TestGrid)
Q_DECLARE_METATYPE(size_t)

class BattleFieldGrid_Test : public QObject
{
    Q_OBJECT

    void test_data();

    TGridSize getGridSize(const TestGrid& grid);
    void fillTestGrid(CBattleFieldGrid<int>& grid, const TestGrid& testGrid);

private slots:

    void test_grid_size_data();
    void test_grid_size();

    void test_push_back_data();
    void test_push_back();

    void test_iterators_data();
    void test_iterators();
};
