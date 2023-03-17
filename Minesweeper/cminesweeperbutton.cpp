#include "cminesweeperbutton.h"
#include <QLayout>
CMineSweeperButton::CMineSweeperButton(const bool hasBomb) : QPushButton(""), _hasBomb(hasBomb)
{
    setCheckable(true);
    setFlat(false);
    setAutoFillBackground(false);

    setMinimumSize(QSize(16, 16));
    setMaximumSize(QSize(16, 16));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(this, &QAbstractButton::clicked, this, &CMineSweeperButton::buttonClicked);
    unreveal();
}

void CMineSweeperButton::buttonSelected()
{
}

void CMineSweeperButton::unreveal()
{
    setText("");
    setChecked(false);
    setEnabled(true);
}

void CMineSweeperButton::reveal()
{

    if (_hasBomb)
    {
        setText("x");
    }

    setChecked(true);
    setEnabled(false);
    emit buttonRevealed();
}

bool CMineSweeperButton::isSelectable() const
{
    return !isChecked();
}

void CMineSweeperButton::buttonClicked(const bool checked)
{
    if (checked)
    {
        setEnabled(false);
        emit buttonSelected();
        reveal();
    }
}
