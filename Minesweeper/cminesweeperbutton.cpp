#include "cminesweeperbutton.h"
#include <QLayout>
#include <QMouseEvent>

CMineSweeperButton::CMineSweeperButton(const unsigned int bombChance) : QPushButton("")
{
    setCheckable(true);
    setFlat(false);
    setAutoFillBackground(false);

    setMinimumSize(QSize(24, 24));
    setMaximumSize(QSize(24, 24));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(this, &QAbstractButton::clicked, this, &CMineSweeperButton::buttonClicked);
    unreveal();

    if ((std::rand() % bombChance) == 0)
        _hasBomb = true;
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
        setIcon(createIcon(":/img/bomb.png"));
    }
    else
    {

        if (_markerSet)
        {
            setIcon(createIcon(QString(":/img/no-bomb.png")));
        }
        else
        {
            if (_bombsAround > 0)
            {
                setIcon(createIcon(QString(":/img/%1.png").arg(_bombsAround)));
            }
        }
    }

    setChecked(true);
    setEnabled(false);
}

bool CMineSweeperButton::isSelectable() const
{
    return !isChecked();
}

bool CMineSweeperButton::hasBomb() const
{
    return _hasBomb;
}

void CMineSweeperButton::setBombsAround(const unsigned int i)
{
    _bombsAround = i;
}

unsigned int CMineSweeperButton::getBombsAround() const
{
    return _bombsAround;
}

void CMineSweeperButton::buttonClicked(const bool checked)
{
    if (!checked)
    {
        return;
    }

    if (_markerSet)
    {
        setMarker();
        setEnabled(true);
        setChecked(false);
        return;
    }

    setEnabled(false);

    if (_hasBomb)
    {
        emit boom();
    }

    emit buttonSelected();
    reveal();
}

void CMineSweeperButton::setMarker()
{
    if (!isEnabled())
    {
        return;
    }

    if (_markerSet)
    {
        _markerSet = false;
        setIcon(QIcon());
    }
    else
    {
        _markerSet = true;
        setIcon(createIcon(":/img/flag.png"));
    }

    emit buttonFlagged(_markerSet);
}

QIcon CMineSweeperButton::createIcon(const QString& path)
{
    QIcon icon;
    icon.addPixmap(QPixmap(path), QIcon::Disabled);
    icon.addPixmap(QPixmap(path), QIcon::Active);
    return icon;
}

void CMineSweeperButton::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::RightButton)
    {
        setMarker();
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
