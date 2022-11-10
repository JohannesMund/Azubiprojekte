#ifndef CFIELD_H
#define CFIELD_H

#include <QLabel>

#include "cplayermanagement.h"

class CField : public QLabel
{
public:
    CField(QWidget* parent = nullptr);
    CPlayerManagement::Player getState() const;
    void setState(const CPlayerManagement::Player& s);
    void reset();
    void setWinningField();

protected:
    /**
     * @brief resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen
     * @param e das ResizeEvent (nicht vergessen weiterzuschicken)
     */
    void resizeEvent(QResizeEvent* e) override;

private:
    CPlayerManagement::Player _state = CPlayerManagement::Player::none;
    void draw();

    bool _isWinningField = false;
};

#endif // CFIELD_H
