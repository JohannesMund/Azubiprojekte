#ifndef CFIELD_H
#define CFIELD_H

#include <QLabel>

#include "cplayermanagement.h"

/**
 * @brief CField Repräsentiert ein Feld auf dem Spielfeld
 */

class CField : public QLabel
{
public:
    CField(QWidget* parent = nullptr);

    /**
     * @brief getState gibt den Zustand des Felds zurück
     * @see CPlayerManagement::Player
     */
    CPlayerManagement::Player getState() const;

    /**
     * @brief setState setzt den Zustand eines feldes
     * @param s der Spieler der das Feld besetzt
     */
    void setState(const CPlayerManagement::Player& s);

    /**
     * @brief reset setzt das Feld zurück
     */
    void reset();

    /**
     * @brief setWinningField setzt ob das Feld zu den Gewinnerfeldern gehört
     * @see CPlayField::checkWinner
     */
    void setWinningField();

protected:
    /**
     * @brief resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen
     * @param e das ResizeEvent (nicht vergessen weiterzuschicken)
     */
    void resizeEvent(QResizeEvent* e) override;

private:
    CPlayerManagement::Player _state = CPlayerManagement::Player::none;
    void draw();

    bool _isWinningField = false;
};

#endif // CFIELD_H
