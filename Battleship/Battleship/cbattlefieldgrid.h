#pragma once
#include "battlefieldcoords.h"
#include "cbattlefieldgriditerator.h"

#include <optional>

/**
 * @brief The TGridSize struct
 * für die Größe bauen wir uns eine Struktur
 * @remark wir könnten QSize nehmen, aber wir wollen lieber size_t als Datentyp und noch die Zählfunktion drin haben.
 */

struct TGridSize
{
    size_t width;
    size_t height;
    size_t numFields() const
    {
        return width * height;
    }
};

/**
 * @brief The CBattleFieldGrid class
 * Wir bauen uns einen eigenen, 2 dimensionalen Container
 * @remark Das Template wäre nicht wirklich notwendig, da wir den Container nur für einen typ brauchen, aber so können
 * wir Temaplates üben uns sehen ein paar tolle Fallstricke.
 * @remark Reden wir über Fallstricke bei Templates.
 * Templatisierte Klassen sind etwas zickig. Der Compiler verzögert das Compilieren, so lange wie es geht, da er ja die
 * möglichen Aufrufe kennen muss. das führt am ende dazu, dass die Klasse eventuell noch nicht kompiliert ist, wenn sie
 * gebraucht wird. Um das zu umgehen, gibt es zwei Möglichleiten:
 * Option 1: Am Ende der Implementierung instantiiert man einach jeden möglichem Aufruf. Das machen wir hier so. Wir
 * erfinden den header
 * @sa cbattlefieldgridregister.h
 * und inkludieren ihn am ende der Implementierung. Jeder, der diesen Container nutzen möchte, trägt sich da ein.
 * Option 2: Wir implementieren alles im Header
 * @sa cbattlefieldgriditerator
 */
template <class TValueType>
class CBattleFieldGrid
{
public:
    /**
     * Typdefinitionen für die Iteratoren
     * @remark Ja, wir bauen uns eigene Iteratoren. Damit diese einfacher zu handhaben sind, definieren wir Typen.
     * @remark Damit wir unseren Container in den STD-Algorithmen und in einer FOREACH Schleife verwenden können,
     * benötigen wir begin- und end- Funktionen, die passende Iteratoren zurückgeben. Beide müssen auch als const
     * vorliegen, damit die Iteratoren auch in konstanten Funktionen benutzt werden können.
     */
    using Iterator = CBattleFieldGridIterator<TValueType, std::vector<std::vector<TValueType>>>;
    using ConstIterator =
        CBattleFieldGridIterator<std::add_const_t<TValueType>, std::add_const_t<std::vector<std::vector<TValueType>>>>;

    /**
     * @brief begin
     * @return der Begin-Iterator
     */
    Iterator begin()
    {
        return Iterator(&_grid, 0, 0);
    }

    /**
     * @brief end
     * @return der Ende-Iterator
     * @remark Achtung! end() zeigt immer HINTER das Ende des Containers, ist als ungültig! Das ist bei Iteratoren
     * Konvention. Der Versuch den end() - Iterator zu dereferenzieren endet in einem Crash.
     */
    Iterator end()
    {
        return Iterator(&_grid, _grid.size(), 0);
    }

    /**
     * @brief begin
     * @return der const Begin-Iterator
     */
    ConstIterator begin() const
    {
        return ConstIterator(&_grid, 0, 0);
    }

    /**
     * @brief end
     * @return der const end-Iterator
     * @remark Auch hier, zeigt hinter das Ende des Containers.
     */
    ConstIterator end() const
    {
        return ConstIterator(&_grid, _grid.size(), 0);
    }

    /**
     * @brief CBattleFieldGrid
     * Ein Standardkonstruktor
     */
    CBattleFieldGrid() = default;

    /**
     * @brief resize
     * Um das push_back zu implementieren wie wir es implementiert haben muss der Container seine Dimensionen kennen.
     * @param sz die größe des Containers
     * @remark Es findet kein resize der Vektoren statt!
     * @remark Die bestehenden Vektoren werden einfach geleert.
     */
    void resize(const TGridSize& sz);

    /**
     * @brief size
     * @return Getter für die Größe
     */
    TGridSize size() const;

    /**
     * @brief clear
     * leert alle vektoren.
     * @remark Die Größe bleibt unangetastet.
     */
    void clear();

    /**
     * @brief at
     * Gibt den Wert an gegebenen Koordinaten zurück
     * @param coords Koordinaten des Wertes
     * @return der Wert an den gegebenen Koordinaten
     * @remark Es findet  keine Zugriffsprüfung statt
     */
    TValueType at(const BattleFieldCoords::BattleFieldCoords coords) const;

    /**
     * @brief push_back
     * schiebt einen wert in das Grid.
     * @param val
     * @return die Koordinaten, an denen der Wert eingefügt wurde
     * @remark Es wird geprüft ob das Grid voll ist. In dem Falle ist das Optional leer.
     * @sa resize
     */
    std::optional<BattleFieldCoords::BattleFieldCoords> push_back(const TValueType& val);

private:
    std::vector<std::vector<TValueType>> _grid;
    TGridSize _sz = {0, 0};
};
