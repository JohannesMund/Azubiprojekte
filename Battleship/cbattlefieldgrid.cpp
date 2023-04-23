#include "cbattlefieldgrid.h"
#include "cbattlefieldbutton.h"

template <typename TContainerType>
void CBattleFieldGrid<TContainerType>::resize(const TGridSize& sz)
{
    clear();
    _sz = sz;
}

template <typename TContainerType>
void CBattleFieldGrid<TContainerType>::clear()
{
    for (auto l : _grid)
    {
        l.clear();
    }
    _grid.clear();
}

template <typename TContainerType>
TContainerType CBattleFieldGrid<TContainerType>::at(const BattleFieldCoords::BattleFieldCoords coords) const
{
    return _grid.at(coords.y).at(coords.x);
}

template <typename TContainerType>
std::optional<BattleFieldCoords::BattleFieldCoords> CBattleFieldGrid<TContainerType>::push_back(
    const TContainerType& val)
{
    if (_grid.empty())
    {
        _grid.push_back(std::vector<TContainerType>{});
    };
    if (_grid.at(_grid.size() - 1).size() >= _sz.width)
    {
        if (_grid.size() >= _sz.height)
        {
            assert(!"we are full!");
            return {};
        }

        _grid.push_back(std::vector<TContainerType>{});
    }
    _grid.at(_grid.size() - 1).push_back(val);

    return BattleFieldCoords::BattleFieldCoords(
        {(unsigned int)_grid.at(_grid.size() - 1).size() - 1, (unsigned int)_grid.size() - 1});
}

template class CBattleFieldGrid<CBattleFieldButton*>;
