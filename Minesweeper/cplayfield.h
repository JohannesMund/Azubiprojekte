#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

#include "cminesweeperbutton.h"

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
        shitLoad
    };

    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    int getNumBombs() const;
    void init(const PlayFieldSize size, const BombCount bombCount);

signals:

    void gameOver(const bool bWin);
    void buttonFlagged(const bool b);

private:
    void deleteButtons();
    void createButtons();
    void addButtonsToLayout();

    void setBombChance(const BombCount bombCount);
    void setPlayFieldSize(const PlayFieldSize size);

    void countAllBombCounts();
    void countBombsAround(const int x, const int y);
    void checkGameOver();

    void revealAll();
    void revealAround(const int x, const int y);
    void lookAround(const int x, const int y);

    void buttonRevealed(const int x, const int y);
    void boom();

    void autoReveal(const int x, const int y);

    void around(const int x, const int y, std::function<void(const int i, const int j)> f);

    int _bombs = 0;

    int _width = 10;
    int _height = 10;
    unsigned int _bombChance = 10;
    std::vector<std::vector<CMineSweeperButton*>> _buttons;
};

#endif // CPLAYFIELD_H
