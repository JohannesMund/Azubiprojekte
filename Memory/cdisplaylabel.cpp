#include "cdisplaylabel.h"
#include "gamemanagement.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QString>

const QColor CDisplayLabel::_player1Color = QColor(255, 0, 0, 25);
const QColor CDisplayLabel::_player2Color = QColor(0, 0, 255, 25);

CDisplayLabel::CDisplayLabel(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
    auto makeLabel = [this](const GameManagement::EPlayer player) -> QLabel*
    {
        QLabel* lb = new QLabel(this);
        lb->setContentsMargins(5, 1, 5, 1);
        lb->setAutoFillBackground(true);

        auto palette = lb->palette();
        if (player == GameManagement::EPlayer::ePlayer1)
        {
            palette.setColor(QPalette::Window, _player1Color);
        }
        else
        {
            palette.setColor(QPalette::Window, _player2Color);
        }
        lb->setPalette(palette);
        return lb;
    };

    _player1Text = makeLabel(GameManagement::EPlayer::ePlayer1);
    _player2Text = makeLabel(GameManagement::EPlayer::ePlayer2);

    _arrow = new QLabel(this);

    QHBoxLayout* pLayout = new QHBoxLayout(this);
    pLayout->addWidget(_player1Text);
    pLayout->addWidget(_arrow);
    pLayout->addWidget(_player2Text);

    setLayout(pLayout);
}

QColor CDisplayLabel::getCurrentPlayerColor()
{
    if (GameManagement::getCurrentPlayer() == GameManagement::EPlayer::ePlayer1)
    {
        return _player1Color;
    }
    return _player2Color;
}

void CDisplayLabel::togglePlayer()
{
    print();
}

void CDisplayLabel::addPoints()
{
    if (GameManagement::getCurrentPlayer() == GameManagement::EPlayer::ePlayer1)
    {
        _pointsPlayer1++;
    }
    else
    {
        _pointsPlayer2++;
    }
    print();
}

void CDisplayLabel::reset()
{
    _pointsPlayer1 = 0;
    _pointsPlayer2 = 0;

    print();
}

void CDisplayLabel::gameOver()
{
    QString title("Spielende");
    QString text("");
    if (_pointsPlayer1 > _pointsPlayer2)
    {
        text = "Spieler 1 gewinnt";
    }
    else if (_pointsPlayer1 < _pointsPlayer2)
    {
        text = "Spieler 2 gewinnt";
    }
    else
    {
        text = "Unentschieden";
    }

    QMessageBox::information(0, title, text);
}

void CDisplayLabel::print()
{
    _player1Text->setText(QString("Player1: %1").arg(_pointsPlayer1));
    _player2Text->setText(QString("Player2: %1").arg(_pointsPlayer2));

    auto f = font();
    f.setBold(true);

    if (GameManagement::getCurrentPlayer() == GameManagement::EPlayer::ePlayer1)
    {
        _player1Text->setFont(f);
        _player2Text->setFont(font());
        _arrow->setText("<-");
    }
    else
    {
        _player1Text->setFont(font());
        _player2Text->setFont(f);
        _arrow->setText("->");
    }
}
