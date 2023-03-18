#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

#include "cminesweeperbutton.h"

class CPlayField : public QFrame
{
    Q_OBJECT
public:
    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    int getNumBombs() const;
    void init();

signals:

    void gameOver(const bool bWin);
    void buttonFlagged(const bool b);

private:
    void createButtons();
    void addButtonsToLayout();

    std::vector<std::vector<CMineSweeperButton*>> _buttons;

    bool outOfXRange(const int i);
    bool outOfYRange(const int i);

    void countAllBombCounts();
    void countBombsAround(const int x, const int y);
    void checkGameOver();

    void revealAll();
    void revealAround(const int x, const int y);
    void lookAround(const int x, const int y);

    void boom();

    int _bombs = 0;

    static constexpr int w = 10;
    static constexpr int h = 10;
    static constexpr unsigned int bombChance = 5;
};

#endif // CPLAYFIELD_H
