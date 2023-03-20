#include "cplayfield.h"

#include <ctime>

#include <QApplication>
#include <QGridLayout>

CPlayField::CPlayField(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
    setLayout(new QGridLayout(this));
}

unsigned int CPlayField::getNumBombs() const
{
    return _bombs;
}

void CPlayField::init(const PlayFieldSize size, const BombCount bombCount)
{
    _bombs = 0;
    setBombChance(bombCount);
    setPlayFieldSize(size);

    deleteButtons();
    createButtons();
    addButtonsToLayout();
}

void CPlayField::deleteButtons()
{
    for (auto& l : _buttons)
    {
        for (auto b : l)
        {
            delete b;
        }
    }
    _buttons.clear();
}

void CPlayField::createButtons()
{
    std::srand(std::time(nullptr));

    for (int i = 0; i < _height; i++)
    {
        std::vector<CMineSweeperButton*> line;
        for (int j = 0; j < _width; j++)
        {
            CMineSweeperButton* p = new CMineSweeperButton(_bombChance);
            connect(p, &CMineSweeperButton::boom, this, &CPlayField::boom);
            connect(p, &CMineSweeperButton::buttonFlagged, this, [this](const bool b) { emit buttonFlagged(b); });
            connect(p, &CMineSweeperButton::buttonSelected, this, [this, i, j]() { buttonRevealed(i, j); });

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
    QGridLayout* l = new QGridLayout(0);

    l->setMargin(0);
    l->setContentsMargins(0, 0, 0, 0);

    for (size_t row = 0; row < _buttons.size(); row++)
    {
        qApp->processEvents();
        const auto line = _buttons.at(row);
        for (size_t col = 0; col < line.size(); col++)
        {
            const auto button = line.at(col);
            l->addWidget(button, static_cast<int>(row), static_cast<int>(col));
        }
    }
    setLayout(l);
}

void CPlayField::setBombChance(const BombCount bombCount)
{
    switch (bombCount)
    {
    case BombCount::little:
    default:
        _bombChance = 12;
        break;
    case BombCount::few:
        _bombChance = 10;
        break;
    case BombCount::many:
        _bombChance = 8;
        break;
    case BombCount::shitLoad:
        _bombChance = 5;
        break;
    }
}

void CPlayField::setPlayFieldSize(const PlayFieldSize size)
{
    switch (size)
    {
    case PlayFieldSize::s:
    default:
        _width = 10;
        _height = 10;
        break;
    case PlayFieldSize::m:
        _width = 15;
        _height = 15;
        break;
    case PlayFieldSize::l:
        _width = 20;
        _height = 20;
        break;
    case PlayFieldSize::xl:
        _width = 50;
        _height = 25;
        break;
    }
}

void CPlayField::countAllBombCounts()
{
    for (int i = 0; i < _buttons.size(); i++)
    {
        for (int j = 0; j < _buttons.at(i).size(); j++)
        {
            countBombsAround(i, j);
        }
    }
}

void CPlayField::countBombsAround(const int x, const int y)
{
    int count = 0;
    around(x,
           y,
           [this, &count](const int i, const int j)
           {
               if (_buttons.at(i).at(j)->hasBomb())
                   count++;
           });

    _buttons.at(x).at(y)->setBombsAround(count);
}

void CPlayField::checkGameOver()
{
    unsigned int checkableFields = 0;
    for (const auto& l : _buttons)
    {
        for (auto& b : l)
        {
            if (b->isSelectable())
                checkableFields++;
        }
    }

    if (checkableFields <= _bombs)
    {
        revealAll();
        emit gameOver(true);
    }
}

void CPlayField::revealAll()
{
    for (const auto& l : _buttons)
    {
        for (auto& b : l)
        {
            b->reveal();
        }
        qApp->processEvents();
    }
}

void CPlayField::revealAround(const int x, const int y)
{
    around(x, y, [this](const int i, const int j) { _buttons.at(i).at(j)->reveal(); });
    qApp->processEvents();
}

void CPlayField::lookAround(const int x, const int y)
{
    _lookedAround.push_back(std::make_pair(x, y));
    around(x, y, [this](const int i, const int j) { autoReveal(i, j); });
}

void CPlayField::buttonRevealed(const int x, const int y)
{
    auto b = _buttons.at(x).at(y);
    if (b->hasBomb())
        return;
    _lookedAround.clear();

    lookAround(x, y);
    checkGameOver();
}

void CPlayField::boom()
{
    revealAll();
    emit gameOver(false);
}

void CPlayField::autoReveal(const int i, const int j)
{
    auto bb = _buttons.at(i).at(j);
    if (bb->getBombsAround() == 0)
    {
        revealAround(i, j);
        if (std::find(_lookedAround.begin(), _lookedAround.end(), std::make_pair(i, j)) == _lookedAround.end())
        {
            lookAround(i, j);
        }
    }
}

void CPlayField::around(const int x, const int y, std::function<void(const int i, const int j)> f)
{
    for (int i = x - 1; i <= x + 1; i++)
    {
        if ((i < 0) || (i >= _height))
            continue;
        for (int j = y - 1; j <= y + 1; j++)
        {
            if ((j < 0) || (j >= _width))
                continue;
            if (j == y && i == x)
                continue;

            f(i, j);
        }
    }
}
