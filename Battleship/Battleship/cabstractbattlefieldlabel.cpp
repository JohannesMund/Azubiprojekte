#include "cabstractbattlefieldlabel.h"

CAbstractBattleFieldLabel::CAbstractBattleFieldLabel(QWidget* parent) : QLabel(parent)
{
    connect(CGameManagement::getInstance(), &CGameManagement::newGame, this, &CAbstractBattleFieldLabel::init);
}

void CAbstractBattleFieldLabel::init()
{
    auto ships = CGameManagement::getInstance()->getAvailableShips();

    _shipsAndHits.clear();
    for (auto s : ships)
    {
        _shipsAndHits.push_back({s, 0});
    }
    update();
}

void CAbstractBattleFieldLabel::update()
{
    QString text("<table>");

    for (unsigned int i = 0; i < _shipsAndHits.size(); i++)
    {
        auto s = _shipsAndHits.at(i);

        auto ship = s.first;
        auto hits = s.second;

        auto shipName = CGameManagement::ship2Text(ship);
        auto hitpoints = CGameManagement::getSizeOfShip(ship);

        QString hitarea;

        hitarea = updateHitArea(i);

        if (hits >= hitpoints)
        {
            hitarea = QStringLiteral("<s>%1</s>").arg(hitarea);
            shipName = QStringLiteral("<s>%1</s>").arg(shipName);
        }
        QString line = QString("<tr><td align=\"right\">%1:</td><td>%3</td></tr>").arg(shipName, hitarea);
        text.append(line);
    }
    text.append("</table>");
    setText(text);
}

void CAbstractBattleFieldLabel::hit(const int id)
{
    _shipsAndHits.at(id).second++;

    update();
}
