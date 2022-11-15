#include "cfield.h"

CField::CField(QWidget* parent) : QLabel(parent)
{

    setMinimumSize(QSize(16, 16));
    setMaximumSize(QSize(256, 256));
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    draw();
}

CPlayerManagement::Player CField::getState() const
{
    return _state;
}

void CField::setState(const CPlayerManagement::Player& s)
{
    _state = s;
    draw();
}

void CField::reset()
{
    setState(CPlayerManagement::Player::none);
    _isWinningField = false;
    draw();
}

void CField::resizeEvent(QResizeEvent* e)
{
    draw();
    QLabel::resizeEvent(e);
}

void CField::setWinningField()
{
    _isWinningField = true;
    draw();
}

void CField::draw()
{
    QSize sz;
    if (width() > height())
    {
        sz = QSize(height() - 5, height() - 5);
    }
    else
    {
        sz = QSize(width() - 5, width() - 5);
    }

    QString filename;
    switch (_state)
    {
    case CPlayerManagement::Player::none:
    default:
        filename = "empty";
        break;
    case CPlayerManagement::Player::red:
        filename = "red";
        break;
    case CPlayerManagement::Player::yellow:
        filename = "yellow";
        break;
    }

    QPixmap p(QPixmap(QString(":/img/%1.png").arg(filename)));

    if (_isWinningField)
    {
        QImage img = p.toImage();
        img.invertPixels();
        p = QPixmap::fromImage(img);
    }

    setPixmap(p.scaled(sz));
}
