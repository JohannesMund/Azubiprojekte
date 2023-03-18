#include "cplayfield.h"

#include <QGridLayout>

CPlayField::CPlayField(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
    setLayout(new QGridLayout(this));
}

int CPlayField::getNumBombs() const
{
    return _bombs;
}

void CPlayField::init()
{
    _bombs = 0;
    createButtons();
    addButtonsToLayout();
}

void CPlayField::createButtons()
{
    std::srand(std::time(nullptr));

    for (int i = 0; i < h; i++)
    {
        std::vector<CMineSweeperButton*> line;
        for (int j = 0; j < w; j++)
        {
            CMineSweeperButton* p = new CMineSweeperButton(bombChance);
            connect(p, &CMineSweeperButton::boom, this, &CPlayField::boom);
            connect(p, &CMineSweeperButton::buttonFlagged, this, [this](const bool b) { emit buttonFlagged(b); });
            connect(p, &CMineSweeperButton::buttonSelected, this, [this, i, j]() { lookAround(i, j); });

            if (p->hasBomb())
                _bombs++;

            line.push_back(p);
        }
        _buttons.push_back(line);
    }
    countAllBombCounts();
}
void CPlayField::addButtonsToLayout()
{
    delete layout();
    QGridLayout* l = new QGridLayout(this);

    l->setMargin(0);
    l->setContentsMargins(0, 0, 0, 0);

    for (size_t row = 0; row < _buttons.size(); row++)
    {
        const auto line = _buttons.at(row);
        for (size_t col = 0; col < line.size(); col++)
        {
            const auto button = line.at(col);
            l->addWidget(button, row, col);
        }
    }
    setLayout(l);
}

bool CPlayField::outOfXRange(const int i)
{
    return (i < 0) || (i >= w);
}

bool CPlayField::outOfYRange(const int i)
{
    return (i < 0) || (i >= h);
}

void CPlayField::countAllBombCounts()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            countBombsAround(i, j);
        }
    }
}

void CPlayField::countBombsAround(const int x, const int y)
{
    auto b = _buttons.at(x).at(y);

    int count = 0;

    for (int i = x - 1; i <= x + 1; i++)
    {
        if (outOfYRange(i))
            continue;
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (outOfXRange(j))
                continue;
            if (j == y && i == x)
                continue;

            if (_buttons.at(i).at(j)->hasBomb())
                count++;
        }
    }

    b->setBombsAround(count);
}

void CPlayField::checkGameOver()
{
    int checkableFields = 0;
    for (const auto& l : _buttons)
    {
        for (auto& b : l)
        {
            if (b->isCheckable())
                checkableFields++;
        }
    }

    if (checkableFields <= _bombs)
        emit gameOver(true);
}

void CPlayField::revealAll()
{
    for (const auto& l : _buttons)
    {
        for (auto& b : l)
        {
            b->reveal();
        }
    }
}

void CPlayField::revealAround(const int x, const int y)
{
    for (int i = x - 1; i <= x + 1; i++)
    {
        if (outOfYRange(i))
            continue;
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (outOfXRange(j))
                continue;
            if (j == y && i == x)
                continue;

            _buttons.at(i).at(j)->reveal();
        }
    }
}

void CPlayField::lookAround(const int x, const int y)
{
    auto b = _buttons.at(x).at(y);
    if (b->hasBomb())
        return;

    for (int i = x - 1; i <= x + 1; i++)
    {
        if (outOfYRange(i))
            continue;
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (outOfXRange(j))
                continue;
            if (j == y && i == x)
                continue;

            auto bb = _buttons.at(i).at(j);
            if (bb->getBombsAround() == 0 && !bb->hasBomb() && bb->isSelectable())
            {
                bb->reveal();
                revealAround(i, j);
                lookAround(i, j);
            }
        }
    }
}

void CPlayField::boom()
{
    revealAll();
    emit gameOver(false);
}
