#pragma once

#include <QObject>
#include <QPushButton>

/**
 * @brief Repräsentiert eine einzelnes Spielfeld */

class CMineSweeperButton : public QPushButton
{
public:
    /**
     * @brief CMineSweeperButton
     */
    CMineSweeperButton(const bool hasBomb);

    /**
     * @brief unreveal dreht eine audgwedeckte Karte um.
     */
    void unreveal();
    /**
     * @brief unreveal dreht eine audgwedeckte Karte um.
     */
    void reveal();

    /**
     * @brief isSelectable prüft ob der Button noch gewählt werden kann
     */
    bool isSelectable() const;

signals:

    void buttonSelected();
    void buttonRevealed();

private:
    void buttonClicked(const bool checked);
    bool _hasBomb;
};
