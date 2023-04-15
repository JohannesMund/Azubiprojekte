#include "cbattlefieldbutton.h"

CBattleFieldButton::CBattleFieldButton() : QPushButton("")
{
    setCheckable(true);
    setFlat(false);
    setAutoFillBackground(false);

    setText("");

    setMinimumSize(QSize(24, 24));
    setMaximumSize(QSize(24, 24));

    setIconSize(QSize(24, 24));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

bool CBattleFieldButton::hasShip()
{
    return _shipId >= 0;
}

int CBattleFieldButton::getShipId()
{
    return _shipId;
}

void CBattleFieldButton::setHasShip(const int id, const bool bShow)
{
    _shipId = id;
    setEnabled(false);
    if (bShow)
    {
        if (id >= 0)
        {
            setIcon(":/img/flag.png");
        }
        else
        {
            clearIcon();
        }
        setChecked(false);
    }
}

void CBattleFieldButton::reveal(const bool bMarkHit)
{
    _isRevealed = true;
    setEnabled(false);

    if (hasShip())
    {
        setIcon(":/img/bomb.png");
        emit hit();
        return;
    }
    if (bMarkHit)
    {
        setIcon(":/img/fadenkreuz.png");
    }
}

bool CBattleFieldButton::isRevealed() const
{
    return _isRevealed;
}

void CBattleFieldButton::setIcon(const QString& path)
{
    QIcon icon;
    icon.addPixmap(QPixmap(path), QIcon::Disabled);
    icon.addPixmap(QPixmap(path), QIcon::Active);
    QPushButton::setIcon(icon);
}

void CBattleFieldButton::clearIcon()
{
    QPushButton::setIcon(QIcon());
}
