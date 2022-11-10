#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

#include "cplayermanagement.h"

class CField;
class CPlayField : public QFrame
{
public:
    CPlayField(QWidget* parent = nullptr);
    void init();

    static constexpr unsigned int _width = 7;
    static constexpr unsigned int _height = 6;

    void addToColumn(const unsigned int column, const CPlayerManagement::Player p);
    bool isColumnFull(const unsigned int column) const;

    CPlayerManagement::Player checkWinner() const;

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

    CField* _grid[_height][_width];
};

#endif // CPLAYFIELD_H
