#pragma once

#include <QFrame>
#include <functional>

#include "cminesweeperbutton.h"

/**
 * @brief CPlayField Repräsentiert das Spielfeld
 */
class CPlayField : public QFrame
{
    Q_OBJECT
public:
    enum class PlayFieldSize
    {
        s,
        m,
        l,
        xl
    };

    enum class BombCount
    {
        little,
        few,
        many,
        shitLoad,
        custom
    };

    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    /**
     * @brief init Initialisiert das Spielfeld
     * @param size Größe des Spielfeldes
     * @param bombCount Menge der Bomben
     */
    void init(const PlayFieldSize size, const BombCount bombCount);

    /**
     * @brief getNumBombs für die Anzahl der Bomben auf dem Feld
     * @return Die tatsächliche Anzahl der Bomben
     */
    unsigned int getNumBombs() const;

signals:

    /**
     * @brief gameOver wird gesendet, wenn das spiel vorbei ist
     * @param bWin gewonnen oder verloren
     */
    void gameOver(const bool bWin);

    /**
     * @brief buttonFlagged wird gesendet, wenn ein button geflagged wird
     * @param bFlag Flag gesetzt oder zurückgesetzt
     */
    void buttonFlagged(const bool bFlag);

private:
    void deleteButtons();

    CMineSweeperButton* createButtonAt(const int x, const int y);
    void createButtons();
    void addButtonsToLayout();

    void setBombChance(const BombCount bombCount);
    void setPlayFieldSize(const PlayFieldSize size);

    void countAllBombCounts();
    void countBombsAround(const int x, const int y);
    void checkGameOver();

    void buttonRevealed(const int x, const int y);
    void boom();

    void revealAll();
    void revealAround(const int x, const int y);
    void autoReveal(const int x, const int y);
    void lookAround(const int x, const int y);

    void around(const int x, const int y, std::function<void(const int i, const int j)> f);

    unsigned int _bombs = 0;
    int _width = 10;
    int _height = 10;
    unsigned int _bombChance = 10;

    std::vector<std::vector<CMineSweeperButton*>> _buttons;

    std::vector<std::pair<int, int>> _lookedAround;
};
