#pragma once

#include <QFrame>

class CAbstractBattleFieldLabel;
class CBattleFieldButton;
class CAbstractBattleField : public QFrame
{

public:
    struct BattleFieldCoords
    {
        unsigned int x;
        unsigned int y;
    };

    CAbstractBattleField(QWidget* parent = nullptr);
    void setLabel(CAbstractBattleFieldLabel* label);

    bool hasShipAround(const BattleFieldCoords coords, std::function<bool(const BattleFieldCoords coords)> f) const;
    bool hasShipAround(const BattleFieldCoords coords) const;

    CBattleFieldButton* get(const BattleFieldCoords coords) const;

protected:
    enum class EDirections
    {
        eHorizontal,
        eVertical
    };

    std::vector<std::vector<CBattleFieldButton*>> _grid;

    void init();

    virtual void placeBattleShips() = 0;
    virtual void startGame() = 0;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords coords) = 0;
    virtual void shipHit(const BattleFieldCoords coords) = 0;

    void clearGrid();

    void enableAll(const bool bEnable);

    bool isInRange(const BattleFieldCoords coords) const;

    CAbstractBattleFieldLabel* _label;
};
