#pragma once

#include <QLabel>

class CDisplay : public QLabel
{
public:
    CDisplay(QWidget* parent = nullptr);
    void setBombs(const int i);
    void addRevealedBomb(const bool b);
    void reset();
    void setGameOver(const bool bWin);

private:
    int _bombs = 0;
    int _bombsRevealed = 0;
    void update();
};
