#pragma once

#include <iterator>
#include <vector>

template <typename TIteratorType, typename TContainerType>

struct CBattleFieldGridIterator
{
public:
    using self_type = CBattleFieldGridIterator;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = std::remove_cv_t<TIteratorType>;
    using pointer = TIteratorType*;
    using reference = TIteratorType&;

    CBattleFieldGridIterator(TContainerType* vv, std::size_t outer, std::size_t inner) :
        _vectorOfVectors(vv),
        _outerIndex(outer),
        _innerIndex(inner)
    {
    }

    const reference operator*() const
    {
        return *this;
    }

    reference operator*()
    {
        return _vectorOfVectors->at(_outerIndex).at(_innerIndex);
    }

    pointer operator->() const
    {
        return this;
    }
    pointer operator->()
    {
        return this;
    }

    // ++prefix operator
    self_type operator++()
    {
        if (_innerIndex + 1 < _vectorOfVectors->at(_outerIndex).size())
        {
            ++_innerIndex;
        }
        else
        {
            ++_outerIndex;
            _innerIndex = 0;
        }
        return *this;
    }

    self_type operator++(int)
    {
        auto retval = *this;
        ++(*this);
        return retval;
    }

    self_type operator--()
    {
        if (_innerIndex > 0)
        {
            --_innerIndex;
        }
        else
        {
            --_outerIndex;
            _innerIndex = _vectorOfVectors->at(_outerIndex).size() - 1;
        }
        return *this;
    }

    self_type operator--(int)
    {
        TIteratorType retval = *this;
        --(*this);
        return retval;
    }
    bool operator==(const self_type& other) const
    {
        return other._vectorOfVectors == _vectorOfVectors && other._outerIndex == _outerIndex &&
               other._innerIndex == _innerIndex;
    }
    bool operator!=(const self_type& other) const
    {
        return !(*this == other);
    }

    size_t x() const
    {
        return _innerIndex;
    }
    size_t y() const
    {
        return _outerIndex;
    }

private:
    TContainerType* _vectorOfVectors;
    std::size_t _outerIndex = 0;
    std::size_t _innerIndex = 0;
};
