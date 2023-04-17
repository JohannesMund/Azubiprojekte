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
}

void CAbstractBattleField::init()
{
    clearGrid();
    delete layout();
    auto l = new QGridLayout(0);

    auto size = CGameManagement::getInstance()->getGridSize();

    l->setMargin(0);
    l->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < size.height(); i++)
    {
        std::vector<CBattleFieldButton*> line;

        for (int j = 0; j < size.width(); j++)
        {
            auto button = new CBattleFieldButton();
            const BattleFieldCoords::BattleFieldCoords coords = {(unsigned)i, (unsigned)j};

            connect(button,
                    &CBattleFieldButton::toggled,
                    this,
                    [coords, this](const bool toggleState) { buttonToggled(toggleState, coords); });

            connect(button, &CBattleFieldButton::hit, this, [coords, this]() { shipHit(coords); });

            line.push_back(button);
            l->addWidget(button, i, j);
        }
        _grid.push_back(line);
    }

    setLayout(l);
    placeBattleShips();
}

void CAbstractBattleField::clearGrid()
{
    for (auto& l : _grid)
    {
        for (auto b : l)
        {
            if (b)
            {
                delete b;
            }
        }
    }
    _grid.clear();
}

void CAbstractBattleField::enableAll(const bool bEnable)
{
    for (auto& l : _grid)
    {
        for (auto b : l)
        {
            b->setEnabled(bEnable);
        }
    }
}

bool CAbstractBattleField::isInRange(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (_grid.size() <= 0)
    {
        return false;
    }
    return (coords.x >= 0 && coords.x < _grid.at(0).size()) && (coords.y >= 0 && coords.y < _grid.size());
}

bool CAbstractBattleField::hasShipAround(const BattleFieldCoords::BattleFieldCoords coords,
                                         std::function<bool(const BattleFieldCoords::BattleFieldCoords coords)> f) const
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

            if (f(coords))
            {
                return true;
            }
        }
    }
    return false;
}

bool CAbstractBattleField::hasShipAround(const BattleFieldCoords::BattleFieldCoords coords) const
{
    return hasShipAround(coords,
                         [this](const BattleFieldCoords::BattleFieldCoords coords)
                         { return _grid.at(coords.x).at(coords.y)->hasShip(); });
}

CBattleFieldButton* CAbstractBattleField::get(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (isInRange(coords))
    {
        return _grid.at(coords.x).at(coords.y);
    }
    return nullptr;
}

void CAbstractBattleField::setLabel(CAbstractBattleFieldLabel* label)
{
    _label = label;
}
