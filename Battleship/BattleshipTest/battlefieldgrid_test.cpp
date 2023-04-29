#include "battlefieldgrid_test.h"
#include "cbattlefieldgriditerator.h"

#include <optional>

void BattleFieldGrid_Test::test_data()
{
    QTest::addColumn<TestGrid>("testGrid");
    QTest::addColumn<size_t>("w");
    QTest::addColumn<size_t>("h");
    QTest::addColumn<size_t>("z");

    QTest::addRow("0") << TestGrid({{{91}, {72}, {83}, {14}},
                                    {{21}, {22}, {53}, {24}},
                                    {{01}, {12}, {13}, {34}},
                                    {{11}, {42}, {73}, {64}}})
                       << 4UL << 4UL << 16UL;

    QTest::addRow("1") << TestGrid({{{11}, {12}}, {{21}, {22}}}) << 2UL << 2UL << 4UL;
    QTest::addRow("2") << TestGrid({{{11}, {12}, {13}}, {{21}, {22}, {23}}, {{31}, {32}, {33}}}) << 3UL << 3UL << 9UL;
    QTest::addRow("3") << TestGrid({{{11}, {12}, {13}, {14}},
                                    {{21}, {22}, {23}, {24}},
                                    {{31}, {32}, {33}, {34}},
                                    {{41}, {42}, {43}, {44}}})
                       << 4UL << 4UL << 16UL;

    QTest::addRow("4") << TestGrid({{{11}, {12}, {13}, {14}}, {{21}, {22}, {23}, {24}}, {{31}, {32}, {33}, {34}}})
                       << 4UL << 3UL << 12UL;
    QTest::addRow("5") << TestGrid({{{11}, {12}, {13}}, {{21}, {22}, {23}}, {{31}, {32}, {33}}, {{41}, {42}, {43}}})
                       << 3UL << 4UL << 12UL;

    QTest::addRow("6") << TestGrid({{{11}, {12}}, {{21}, {22}}, {{31}, {32}}, {{41}, {42}}}) << 2UL << 4UL << 8UL;
    QTest::addRow("7") << TestGrid({{{11}, {12}, {13}, {14}}, {{21}, {22}, {23}, {24}}}) << 4UL << 2UL << 8UL;
}

TGridSize BattleFieldGrid_Test::getGridSize(const TestGrid& grid)
{
    TGridSize sz;

    if (!grid.size())
    {
        return sz;
    }

    if (!grid.at(0).size())
    {
        return sz;
    }
    sz.height = grid.size();
    sz.width = grid.at(0).size();

    return sz;
}

void BattleFieldGrid_Test::fillTestGrid(CBattleFieldGrid<int>& grid, const TestGrid& testGrid)
{
    grid.resize(getGridSize(testGrid));

    for (auto line : testGrid)
    {
        for (auto i : line)
        {
            grid.push_back(i);
        }
    }
}

void BattleFieldGrid_Test::test_grid_size_data()
{
    test_data();
}

void BattleFieldGrid_Test::test_grid_size()
{

    QFETCH(TestGrid, testGrid);
    QFETCH(size_t, w);
    QFETCH(size_t, h);
    QFETCH(size_t, z);

    TGridSize sz = getGridSize(testGrid);

    QCOMPARE(sz.width, w);
    QCOMPARE(sz.height, h);
    QCOMPARE(sz.numFields(), z);
}

void BattleFieldGrid_Test::test_push_back_data()
{
    test_data();
}

void BattleFieldGrid_Test::test_push_back()
{
    QFETCH(TestGrid, testGrid);
    auto sz = getGridSize(testGrid);

    CBattleFieldGrid<int> grid;

    fillTestGrid(grid, testGrid);

    QCOMPARE(grid.size().width, sz.width);
    QCOMPARE(grid.size().height, sz.height);
    QCOMPARE(grid.size().numFields(), sz.numFields());

    QVERIFY(!grid.push_back(0).has_value());

    for (unsigned int i = 0; i < testGrid.size(); i++)
    {
        const auto line = testGrid.at(i);
        for (unsigned int j = 0; j < line.size(); j++)
        {
            QCOMPARE(grid.at({j, i}), line.at(j));
        }
    }
}

void BattleFieldGrid_Test::test_iterators_data()
{
    test_data();
}

void BattleFieldGrid_Test::test_iterators()
{

    QFETCH(TestGrid, testGrid);
    CBattleFieldGrid<int> grid;

    fillTestGrid(grid, testGrid);

    for (auto it = grid.begin(); it != grid.end(); ++it)
    {
        auto val = testGrid.at(it.y()).at(it.x());
        QCOMPARE(val, *it);
    }
    std::sort(grid.begin(), grid.end());

    int last = 0;
    for (auto current : grid)
    {
        QVERIFY(last <= current);
        last = current;
    }

    auto it = grid.begin();
    ++it;
    QVERIFY(*it == grid.at({1, 0}));
    --it;
    QVERIFY(it == grid.begin());

    --it;
    QVERIFY(it == grid.begin());

    it = it + 1;
    QVERIFY(*it == grid.at({1, 0}));

    it = grid.end();
    ++it;
    auto iitt = grid.end();
    QVERIFY(it == iitt);

    it = it + 5;
    QVERIFY(it == grid.end());
}
