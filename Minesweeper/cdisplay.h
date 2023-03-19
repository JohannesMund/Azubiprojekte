#pragma once

#include <QLabel>

/**
 * @brief CDisplay repräsentiert die Anzeige
 */
class CDisplay : public QLabel
{
public:
    CDisplay(QWidget* parent = nullptr);

    /**
     * @brief setBombs Setter für die Anzahl der Bomben
     * @param i Anzahl der Bomben
     */
    void setBombs(const int i);

    /**
     * @brief setGameOver Anzeige für Game over
     * @param bWin gewonnen oder verloren
     */
    void setGameOver(const bool bWin);

    /**
     * @brief addRevealedBomb fügt eine markierte Bombe hinzu, oder entfernt sie
     * @param bAdd hinzufügen oder entfernen
     */
    void addRevealedBomb(const bool bAdd);

    /**
     * @brief reset setzt die Anzeige zurück
     */
    void reset();

private:
    int _bombs = 0;
    int _bombsRevealed = 0;
    void update();
};
