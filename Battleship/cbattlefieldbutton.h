#pragma once

#include "cgamemanagement.h"

#include <QPushButton>

class CBattleFieldButton : public QPushButton
{
    Q_OBJECT
public:
    CBattleFieldButton();
    bool hasShip() const;
    int getShipId() const;

    void setHasShip(const int id, const bool bShow);

    void reveal(const bool bMarkHit = false);

    bool isRevealed() const;

    bool isRevealedHit() const;

signals:
    void hit();

private:
    void setIcon(const QString& path);
    void clearIcon();
    int _shipId = CGameManagement::InvalidShipId;
    bool _isRevealed = false;
};
