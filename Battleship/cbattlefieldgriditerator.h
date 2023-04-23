#pragma once

#include <iterator>
#include <vector>

/**
 * @brief The CBattleFieldGridIterator class
 * Wir bauen uns einen Iterator für einen 2 dimensionalen Vektor
 * @remark Ist es sinnvoll einen Container zu erfinden, und einen Iterator dafür zu bauen, wenn sich das mit STL
 * Containern umsetzen ließe? - NEIN!
 * Ist es einfacher einen Container zu erfinden, und einen Iterator dafür zu bauen, wenn sich das mit STL
 * Containern umsetzen ließe? - Um Gottes Willen, NEIN!
 * Machen wir es trotzdem? - FUCK YEAH!
 * Warum? - Weil wir es können!
 * @remark - Wir implementieren alles in den Header. Das ist nicht schön, aber wir haben eine Template Klasse, und
 * müssen den Compiler zwingen die Klasse kompiliert zu haben, wenn wir sie Brauchen. Das ist eine Möglichkeit, die
 * andere Option findet sich im Container.
 * @sa CBattleFieldGrid
 */

template <typename TIteratorType, typename TContainerType>
struct CBattleFieldGridIterator
{
public:
    /**
     * @remark Diese definitionen sind notwendig, damit der Compiler das ganze Konstrukt als Iterator nutzen kann
     * Wie bauen einen bidirektionalen Iterator, man kann also in beide Richtungen iterieren.
     */

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = std::remove_cv_t<TIteratorType>;
    using pointer = TIteratorType*;
    using reference = TIteratorType&;

    /**
     * für die Bessere Lesbarkeit
     * der self_type ist nicht notwendig.
     */
    using self_type = CBattleFieldGridIterator;

    /**
     * @brief CBattleFieldGridIterator
     * Im Konstruktor bekommt der Iterator einen Zeiger auf das Grid, und eine Startposition
     * @param vv Zeiger auf den Container
     * @param outer y-Pos
     * @param inner x-Pos
     */

    CBattleFieldGridIterator(TContainerType* vv, std::size_t outer, std::size_t inner) :
        _vectorOfVectors(vv),
        _outerIndex(outer),
        _innerIndex(inner)
    {
    }

    /**
     * Ab hier Standard. Alle Iteratoren müssen die folgenden Operatoren implementieren. Die Zugriffsopteratoren (* und
     * ->) müssen const und nicht-const vorhanden sein. Aufpassen beim Lesen, *this benutzt den ersten *-Operatore zum
     * dereferenzieren des Wertes. (Also das, was der Iterator landläufig so macht.) Natürlich implementieren wir den
     * Zugriff nur einmal und benutzen ihn dann.
     */

    reference operator*()
    {
        return _vectorOfVectors->at(_outerIndex).at(_innerIndex);
    }

    const reference operator*() const
    {
        return *this;
    }

    pointer operator->() const
    {
        return this;
    }
    pointer operator->()
    {
        return this;
    }

    /**
     * Inkrement und Dekrement jeweils als Postfix und als Prefix
     * Auch hier wieder einmal implementieren und dann nutzen.
     * Wir greifen auch auf den reference operator zurück
     */

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

    /**
     * Und zu guter Letzt muss der Kram noch vergleichbar sein.
     */

    bool operator==(const self_type& other) const
    {
        return other._vectorOfVectors == _vectorOfVectors && other._outerIndex == _outerIndex &&
               other._innerIndex == _innerIndex;
    }
    bool operator!=(const self_type& other) const
    {
        return !(*this == other);
    }

    /**
     * @brief x
     * der Iterator soll auch seine Position verraten
     * @return x-coordinate
     */
    size_t x() const
    {
        return _innerIndex;
    }

    /**
     * @brief y
     * der Iterator soll auch seine Position verraten
     * @return y-coordinate
     */
    size_t y() const
    {
        return _outerIndex;
    }

private:
    TContainerType* _vectorOfVectors;
    std::size_t _outerIndex = 0;
    std::size_t _innerIndex = 0;
};
