#ifndef CBUTTONBOX_H
#define CBUTTONBOX_H

#include <QFrame>

class QPushButton;
class CButtonBox : public QFrame
{
    Q_OBJECT
public:
    CButtonBox(QWidget* parent = nullptr);
    void deactivateButton(const unsigned int index);
    void reset();

signals:
    void buttonClicked(const unsigned int index);

private:
    std::vector<QPushButton*> _buttons;
};

#endif // CBUTTONBOX_H
