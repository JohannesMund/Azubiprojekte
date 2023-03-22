#pragma once

#include <QObject>
#include <QPair>
#include <QPushButton>

/**
 * @brief Repräsentiert eine einzelnes Spielfeld */

class CMineSweeperButton : public QPushButton
{

    Q_OBJECT
public:
    /**
     * @brief CMineSweeperButton
     */
    CMineSweeperButton(const unsigned int bombChance);

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

    /**
     * @brief hasBomb prüft, ob der Button eine Bombe enthält
     */
    bool hasBomb() const;

    /**
     * @brief setBombsAround wiviele Bomben sind um den Button herum
     * @param i die Anzahl der Bomben drumherum
     */
    void setBombsAround(const unsigned int i);

    /**
     * @brief getBombsAround prüft, wieviele bomben um den Button herum sind
     * @return die Anzahl der Bomben drumherum
     */
    unsigned int getBombsAround() const;

signals:

    /**
     * @brief boom wird gesendet, wenn der Spieler eine Bombe aufdeckt
     */
    void boom();

    /**
     * @brief buttonSelected wird gesendet, wenn der Spieler das Feld aufdeckt
     */
    void buttonSelected();

    /**
     * @brief buttonFlagged wird gesetzt, wenn der Spieler den Button markiert
     * @param b
     */
    void buttonFlagged(const bool b);

private:
    void buttonClicked(const bool checked);
    void setMarker();

    QIcon createIcon(const QString& path);

    bool _markerSet = false;
    bool _hasBomb = false;

    unsigned int _bombsAround = 0;

private slots:
    /**
     * @brief mousePressEvent re-implementierung um den rechten Mausbutton abzufangen
     * @param e
     */
    void mousePressEvent(QMouseEvent* e);
};
