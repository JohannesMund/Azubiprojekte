#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

#include "cplayermanagement.h"

class CField;

/**
 * @brief CPlayField Das Spielfeld
 */

class CPlayField : public QFrame
{
public:
    static constexpr unsigned int _width = 7;
    static constexpr unsigned int _height = 6;

    CPlayField(QWidget* parent = nullptr);

    /**
     * @brief addToColumn fügt Spieler p zu Spalte column hinzu
     * @remark packt den Spielstein oben drauf
     * @see getTopEmptyField
     */
    void addToColumn(const unsigned int column, const CPlayerManagement::Player p);

    /**
     * @brief isColumnFull ermittelt, ob Spalte column voll ist
     */
    bool isColumnFull(const unsigned int column) const;

    /**
     * @brief checkWinner prüft, ob es einen Gewinner gibt
     * @return den Gewinner oder CPlayerManagement::Player::none
     */
    CPlayerManagement::Player checkWinner() const;

    /**
     * @brief reset setzt das Spielfeld zurück
     */
    void reset();

private:
    CPlayerManagement::Player winnerInRow(const unsigned int row) const;
    CPlayerManagement::Player winnerInDiagonale(const unsigned int row) const;
    CPlayerManagement::Player winnerInColumn(const unsigned int column) const;
    CPlayerManagement::Player winnerInCombination(CField* f1, CField* f2, CField* f3, CField* f4) const;
    CField* getTopEmptyField(const unsigned int column) const;

    void setField(const unsigned int row, const unsigned int column, CField* pField);

    CPlayerManagement::Player getFieldState(const unsigned int row, const unsigned int column) const;
    CField* getField(const unsigned int row, const unsigned int column) const;

    void init();

    CField* _grid[_height][_width];
};

#endif // CPLAYFIELD_H
