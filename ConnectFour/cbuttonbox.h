#ifndef CBUTTONBOX_H
#define CBUTTONBOX_H

#include <QFrame>

class QPushButton;

/**
 * @brief Die Box, die die Buttons enthält. Ein Button pro Spalte
 */
class CButtonBox : public QFrame
{
    Q_OBJECT
public:
    CButtonBox(QWidget* parent = nullptr);

    /**
     * @brief deactivateButton deaktiviert den Button für Spalte index
     */
    void deactivateButton(const unsigned int index);

    /**
     * @brief reset setzt die Buttons zurück
     */
    void reset();

signals:

    /**
     * @brief buttonClicked wird gesendet, wenn ein Button geklicked wird. Gibt den Index der zugehörigen Spalte mit
     */
    void buttonClicked(const unsigned int index);

private:
    std::vector<QPushButton*> _buttons;
};

#endif // CBUTTONBOX_H
