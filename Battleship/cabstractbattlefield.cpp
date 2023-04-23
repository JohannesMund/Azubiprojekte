#include "cabstractbattlefield.h"
#include "cabstractbattlefieldlabel.h"
#include "cbattlefieldbutton.h"
#include "cgamemanagement.h"

#include <QApplication>
#include <QGridLayout>

CAbstractBattleField::CAbstractBattleField(QWidget* parent) : QFrame(parent)
{
    setLayout(new QGridLayout(this));
    connect(CGameManagement::getInstance(), &CGameManagement::newGame, this, &CAbstractBattleField::init);
    connect(CGameManagement::getInstance(), &CGameManagement::startGame, this, &CAbstractBattleField::startGame);
    connect(CGameManagement::getInstance(), &CGameManagement::gameOver, this, &CAbstractBattleField::revealAll);
}

void CAbstractBattleField::init()
{
    clearGrid();
    delete layout();
    auto l = new QGridLayout(0);

    auto size = CGameManagement::getInstance()->getGridSize();
    _grid.resize(size);

    l->setContentsMargins(0, 0, 0, 0);

    for (size_t i = 0; i < size.numFields(); i++)
    {
        auto button = new CBattleFieldButton();
        const auto coords = _grid.push_back(button);

        if (!coords.has_value())
        {
            assert(!"Das sollte nicht passieren");
            break;
        }

        connect(button,
                &CBattleFieldButton::toggled,
                this,
                [coords, this](const bool toggleState) { buttonToggled(toggleState, *coords); });

        connect(button, &CBattleFieldButton::hit, this, [coords, this]() { shipHit(*coords); });

        l->addWidget(button, coords->x, coords->y);
    }

    setLayout(l);
    placeBattleShips();
}

void CAbstractBattleField::clearGrid()
{
    for (auto b : _grid)
    {
        delete (b);
    }
    _grid.clear();
}

void CAbstractBattleField::enableAll(const bool bEnable)
{
    for (auto b : _grid)
    {
        b->setEnabled(bEnable);
    }
}

void CAbstractBattleField::revealAll()
{
    for (auto b : _grid)
    {
        b->reveal(false);
        b->setEnabled(false);
    }
}

bool CAbstractBattleField::isInRange(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (_grid.size().height <= 0)
    {
        return false;
    }
    return (coords.x < _grid.size().width) && (coords.y < _grid.size().height);
}

bool CAbstractBattleField::checkForWin() const
{
    /**
     * @remark das geht nur, weil wir eigene Iteratoren benutzen
     */
    unsigned int cnt =
        std::count_if(_grid.begin(), _grid.end(), [](const CBattleFieldButton* b) { return b->isRevealedHit(); });
    if (cnt >= CGameManagement::getInstance()->getHitsForWin())
    {
        return true;
    }
    return false;
}

bool CAbstractBattleField::hasShipAround_if(const BattleFieldCoords::BattleFieldCoords coords, fnAround fn) const
{
    for (int i = coords.x - 1; i <= static_cast<int>(coords.x + 1); i++)
    {
        for (int j = coords.y - 1; j <= static_cast<int>(coords.y + 1); j++)
        {
            const BattleFieldCoords::BattleFieldCoords coords = {(unsigned)i, (unsigned)j};

            if (!isInRange(coords))
            {
                continue;
            }

            auto s = at(coords);
            if (fn(s))
            {
                return true;
            }
        }
    }
    return false;
}

bool CAbstractBattleField::hasShipAround(const BattleFieldCoords::BattleFieldCoords coords) const
{
    return hasShipAround_if(coords, [this](const auto b) { return b->hasShip(); });
}

CBattleFieldButton* CAbstractBattleField::at(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (isInRange(coords))
    {
        return _grid.at(coords);
    }
    return nullptr;
}

void CAbstractBattleField::setLabel(CAbstractBattleFieldLabel* label)
{
    _label = label;
}
