#pragma once

#include "cgamemanagement.h"

#include <QPushButton>

/**
 * @brief The CBattleFieldButton class
 * Ein Button auf dem Spielfeld. Der Button weiß ob ein Schiff zu ihm gehört, und kenn die ID des schiffs
 */

class CBattleFieldButton : public QPushButton
{
    Q_OBJECT
public:
    CBattleFieldButton();

    /**
     * @brief hasShip
     * Hat der Button ein Schiff?
     */
    bool hasShip() const;

    /**
     * @brief setHasShip
     * Setter, gibt den Button ein Schiff
     * @param id
     * @param bShow gibt an ob der Button auch markiert werden soll (für das Placement des Spielers
     */
    void setHasShip(const int id, const bool bShow);

    /**
     * @brief getShipId
     * Gibt die SchiffsID zurück
     */
    int getShipId() const;

    /**
     * @brief reveal
     * Deckt den Button auf. Der Button ist danach nicht mehr klickbar. Wenn er ein Schiff enthält, zeigt er eine
     * Explosion an.
     * @param bMarkHit wenn der Button kein Schiff kann er trotzdem markiert werden, z.B. um zu zeigen, wo der Computer
     * hingeschossen hat.
     */
    void reveal(const bool bMarkHit = false);
    bool isRevealed() const;
    bool isRevealedHit() const;

signals:
    /**
     * @brief hit
     * wird gesendet, wenn der Button aufgedeckt wird, und ein Schiff enthält.
     */
    void hit();

private:
    void setIcon(const QString& path);
    void clearIcon();
    int _shipId = CGameManagement::InvalidShipId;
    bool _isRevealed = false;
};
