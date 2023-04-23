#pragma once
#include "battlefieldcoords.h"
#include "cbattlefieldgriditerator.h"

struct TGridSize
{
    size_t width;
    size_t height;
    size_t numFields() const
    {
        return width * height;
    }
};

template <class TValueType>
class CBattleFieldGrid
{
public:
    using Iterator = CBattleFieldGridIterator<TValueType, std::vector<std::vector<TValueType>>>;
    using ConstIterator =
        CBattleFieldGridIterator<std::add_const_t<TValueType>, std::add_const_t<std::vector<std::vector<TValueType>>>>;

    Iterator begin()
    {
        return Iterator(&_grid, 0, 0);
    }
    Iterator end()
    {
        return Iterator(&_grid, _grid.size(), 0);
    }

    ConstIterator begin() const
    {
        return ConstIterator(&_grid, 0, 0);
    }
    ConstIterator end() const
    {
        return ConstIterator(&_grid, _grid.size(), 0);
    }

    CBattleFieldGrid()
    {
    }

    TGridSize size() const
    {
        return {_grid.at(_grid.size() - 1).size(), _grid.size()};
    }

    void resize(const TGridSize& sz);
    void clear();

    TValueType at(const BattleFieldCoords::BattleFieldCoords coords) const;

    std::optional<BattleFieldCoords::BattleFieldCoords> push_back(const TValueType& val);

private:
    std::vector<std::vector<TValueType>> _grid;
    TGridSize _sz = {0, 0};
};
