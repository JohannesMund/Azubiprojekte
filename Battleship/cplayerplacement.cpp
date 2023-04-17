#include "cplayerplacement.h"

#include <QLabel>

CPlayerPlacement::CPlayerPlacement()
{
}

void CPlayerPlacement::init(QLabel* label)
{
    _label = label;
    _ships = CGameManagement::getInstance()->getAvailableShips();
    _currentId = 0;
    _label->setText(placementText());
}

int CPlayerPlacement::currentId() const
{
    return _currentId;
}

CGameManagement::EShips CPlayerPlacement::currentShip() const
{
    if (_currentId > -1 && _currentId < (int)_ships.size())
    {
        return _ships.at(_currentId);
    }
    return CGameManagement::EShips::eNoShip;
}

void CPlayerPlacement::next()
{
    _moves.clear();
    _currentId++;
    if (_currentId >= (int)_ships.size())
    {
        _currentId = -1;
        CGameManagement::getInstance()->start();
    }
}

bool CPlayerPlacement::isDone() const
{
    return _currentId == -1;
}

QString CPlayerPlacement::placementText() const
{
    if (isDone())
    {
        return QString();
    }

    QString text;

    const auto makeTextLine = [](CGameManagement::EShips ship)
    { return QString("%1 (%2)<br/>").arg(CGameManagement::ship2Text(ship)).arg(CGameManagement::getSizeOfShip(ship)); };

    for (unsigned int i = 0; i < _ships.size(); i++)
    {
        if ((int)i >= _currentId)
        {
            break;
        }

        auto ship = _ships.at(i);
        text.append(makeTextLine(ship));
    }

    text.append("Now Placing:<br/>");
    auto ship = _ships.at(_currentId);
    text.append(makeTextLine(ship));

    return text;
}

void CPlayerPlacement::set(const BattleFieldCoords::BattleFieldCoords coords)
{
    BattleFieldCoords::ShipAtCoords s = {coords, (unsigned)currentId()};

    if (!_moves.isInLine(s))
    {
        emit unsetButtons(_moves);
        _moves.clear();
    }

    _moves.push_back(s);
    emit setButton(s);

    if (_moves.size() >= CGameManagement::getSizeOfShip(currentShip()))
    {
        next();
    }

    if (_label == nullptr)
        return;

    auto text = placementText();

    if (!text.isEmpty())
    {
        _label->setText(text);
    }
}
