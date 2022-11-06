#ifndef CPLAYFIELD_H
#define CPLAYFIELD_H

#include <QFrame>

class CMemoryButton;
class CPlayField : public QFrame
{
    Q_OBJECT
public:
    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void init(const int fields);

    static const int _maxFields;

signals:
    void togglePlayer();
    void playerScored();

private:
    void buttonClicked(const unsigned int index);

    void clearButtons();

    static std::vector<unsigned int> generateRandomNumbers(const int number);

    CMemoryButton* _btnPressed1 = nullptr;
    CMemoryButton* _btnPressed2 = nullptr;

    std::vector<CMemoryButton*> _buttons = {};
};

#endif // CPLAYFIELD_H
