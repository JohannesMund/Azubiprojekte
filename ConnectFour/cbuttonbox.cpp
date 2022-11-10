#include "cbuttonbox.h"
#include "cplayfield.h"

#include <QHBoxLayout>
#include <QPushButton>

CButtonBox::CButtonBox(QWidget* parent) : QFrame(parent)
{
    QHBoxLayout* pLayout = new QHBoxLayout(this);

    for (unsigned int i = 0; i < CPlayField::_width; i++)
    {
        auto p = new QPushButton("", this);
        connect(p, &QPushButton::clicked, this, [=]() { emit buttonClicked(i); });
        pLayout->insertWidget(i, p);
        _buttons.push_back(p);
    }

    setLayout(pLayout);
}

void CButtonBox::deactivateButton(const unsigned int index)
{
    _buttons.at(index)->setEnabled(false);
    _buttons.at(index)->setFlat(true);
}

void CButtonBox::reset()
{
    for (auto b : _buttons)
    {
        b->setEnabled(true);
        b->setFlat(false);
    }
}
