#include "cdisplay.h"

CDisplay::CDisplay(QWidget* parent) : QLabel(parent)
{
}

void CDisplay::setBombs(const int i)
{
    _bombsRevealed = 0;
    _bombs = i;
    update();
}

void CDisplay::addRevealedBomb(const bool b)
{
    if (b)
        _bombsRevealed++;
    else
        _bombsRevealed--;

    update();
}

void CDisplay::reset()
{
    _bombsRevealed = 0;
    _bombs = 0;
    update();
}

void CDisplay::setGameOver(const bool bWin)
{
    if (bWin)
    {
        setText("Gewonnen!");
    }
    else
    {
        setText(".oO(BOOOOM)Oo.");
    }
}

void CDisplay::update()
{
    setText(QString("Bomben: %1/%2").arg(_bombsRevealed).arg(_bombs));
}
