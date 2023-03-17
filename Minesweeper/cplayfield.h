#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

#include "cminesweeperbutton.h"

class CPlayField : public QFrame
{
public:
    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void init();

private:
    void createButtons();
    void addButtonsToLayout();

    std::vector<std::vector<CMineSweeperButton*>> _buttons;
};

#endif // CPLAYFIELD_H
