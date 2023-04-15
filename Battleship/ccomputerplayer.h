#ifndef CCOMPUTERPLAYER_H
#define CCOMPUTERPLAYER_H

#include "cabstractbattlefield.h"

#include <QObject>

class CComputerPlayer : public QObject
{
public:
    explicit CComputerPlayer(CAbstractBattleField* battleField, QObject* parent = nullptr);

    void init();

private:
    void doMove();

    std::vector<CAbstractBattleField::BattleFieldCoords> getAvailableFields();
    CAbstractBattleField* _battleField;

    std::vector<unsigned int> _sunkShips = {};
};

#endif // CCOMPUTERPLAYER_H
