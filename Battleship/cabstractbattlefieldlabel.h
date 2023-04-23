#pragma once

#include "cgamemanagement.h"

#include <QLabel>

/**
 * @brief The CAbstractBattleFieldLabel class
 * Ein Abstraktes Label das Treffer zählt und darstellt
 * @remark pure virtual, muss also noch abgeleitet werden.
 */

class CAbstractBattleFieldLabel : public QLabel
{
public:
    /**
     * @brief hit
     * Ein Schiff wurde getroffen
     * @param id
     */
    void hit(const int id);

    /**
     * @brief update
     * Aktualisiert das Label
     */
    void update();

protected:
    CAbstractBattleFieldLabel(QWidget* parent = nullptr);

    void init();

    /**
     * @brief updateHitArea
     * Wir wollen, dass beim Gegner nur angezeitg wird, wenn ein Schiff versenkt wird, beim Spieler die Treffer.
     * Deswegen muss diese FUnktion abgeleitet werden.
     * @param shipId
     * @return
     */
    virtual QString updateHitArea(const int shipId) = 0;

    std::vector<std::pair<CGameManagement::EShips, unsigned int>> _shipsAndHits;
};
