#include "cplayfield.h"
#include "cfield.h"
#include <QGridLayout>

CPlayField::CPlayField(QWidget* parent) : QFrame(parent)
{
    setLayout(new QGridLayout(this));
    init();
}

void CPlayField::init()
{
    QGridLayout* pLayout = qobject_cast<QGridLayout*>(layout());

    for (unsigned int row = 0; row < _height; row++)
    {
        pLayout->setRowStretch(row, 1);
        for (unsigned int column = 0; column < _width; column++)
        {
            pLayout->setColumnStretch(column, 1);
            auto field = new CField(this);
            pLayout->addWidget(field, row, column);

            setField(row, column, field);
        }
    }
}

void CPlayField::addToColumn(const unsigned int column, const CPlayerManagement::Player p)
{
    auto field = getTopEmptyField(column);
    if (field != nullptr)
    {
        field->setState(p);
    }
}

bool CPlayField::isColumnFull(const unsigned int column) const
{
    return getField(0, column)->getState() != CPlayerManagement::Player::none;
}

CPlayerManagement::Player CPlayField::checkWinner() const
{
    for (unsigned int i = 0; i < _width; i++)
    {
        auto p = winnerInColumn(i);
        if (p != CPlayerManagement::Player::none)
        {
            return p;
        }
    }

    for (unsigned int i = 0; i < _height; i++)
    {
        auto p = winnerInRow(i);
        if (p != CPlayerManagement::Player::none)
        {
            return p;
        }
    }
    for (unsigned int i = 0; i < _height - 3; i++)
    {
        auto p = winnerInDiagonale(i);
        if (p != CPlayerManagement::Player::none)
        {
            return p;
        }
    }

    return CPlayerManagement::Player::none;
}

void CPlayField::reset()
{
    for (unsigned int i = 0; i < _width; i++)
    {
        for (auto j = 0; j < _height; j++)
        {
            getField(j, i)->reset();
        }
    }
}

CPlayerManagement::Player CPlayField::winnerInRow(const unsigned int row) const
{
    for (unsigned int i = 0; i < _width - 3; i++)
    {
        auto f1 = getField(row, i);
        auto f2 = getField(row, i + 1);
        auto f3 = getField(row, i + 2);
        auto f4 = getField(row, i + 3);
        auto f = winnerInCombination(f1, f2, f3, f4);
        if (f != CPlayerManagement::Player::none)
        {
            return f;
        }
    }
    return CPlayerManagement::Player::none;
}

CPlayerManagement::Player CPlayField::winnerInDiagonale(const unsigned int row) const
{
    for (unsigned int i = 0; i < _width - 3; i++)
    {
        auto f1 = getField(row, i);
        auto f2 = getField(row + 1, i + 1);
        auto f3 = getField(row + 2, i + 2);
        auto f4 = getField(row + 3, i + 3);
        auto f = winnerInCombination(f1, f2, f3, f4);
        if (f != CPlayerManagement::Player::none)
        {
            return f;
        }
    }

    for (unsigned int i = _width - 1; i > 2; i--)
    {
        auto f1 = getField(row, i);
        auto f2 = getField(row + 1, i - 1);
        auto f3 = getField(row + 2, i - 2);
        auto f4 = getField(row + 3, i - 3);
        auto f = winnerInCombination(f1, f2, f3, f4);
        if (f != CPlayerManagement::Player::none)
        {
            return f;
        }
    }

    return CPlayerManagement::Player::none;
}

CPlayerManagement::Player CPlayField::winnerInColumn(const unsigned int column) const
{
    for (unsigned int i = 0; i < _height - 3; i++)
    {
        auto f1 = getField(i, column);
        auto f2 = getField(i + 1, column);
        auto f3 = getField(i + 2, column);
        auto f4 = getField(i + 3, column);

        auto f = winnerInCombination(f1, f2, f3, f4);
        if (f != CPlayerManagement::Player::none)
        {
            return f;
        }
    }
    return CPlayerManagement::Player::none;
}

CPlayerManagement::Player CPlayField::winnerInCombination(CField* f1, CField* f2, CField* f3, CField* f4) const
{
    auto f1s = f1->getState();
    auto f2s = f2->getState();
    auto f3s = f3->getState();
    auto f4s = f4->getState();

    if (f1s == CPlayerManagement::Player::none || f2s == CPlayerManagement::Player::none ||
        f3s == CPlayerManagement::Player::none || f4s == CPlayerManagement::Player::none)
    {
        return CPlayerManagement::Player::none;
    }

    if (f1s == f2s && f1s == f3s && f1s == f4s)
    {
        f1->setWinningField();
        f2->setWinningField();
        f3->setWinningField();
        f4->setWinningField();
        return f1s;
    }
    return CPlayerManagement::Player::none;
}

CField* CPlayField::getTopEmptyField(const unsigned int column) const
{
    for (int i = _height - 1; i >= 0; i--)
    {
        auto field = getField(i, column);
        if (field->getState() == CPlayerManagement::Player::none)
        {
            return field;
        }
    }
    return nullptr;
}

void CPlayField::setField(const unsigned int row, const unsigned int column, CField* pField)
{
    _grid[row][column] = pField;
}

CPlayerManagement::Player CPlayField::getFieldState(const unsigned int row, const unsigned int column) const
{
    return getField(row, column)->getState();
}

CField* CPlayField::getField(const unsigned int row, const unsigned int column) const
{
    return _grid[row][column];
}
