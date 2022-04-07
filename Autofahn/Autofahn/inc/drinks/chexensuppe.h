#ifndef CHEXENSUPPE_H
#define CHEXENSUPPE_H

#include "cdrink.h"

/**
 * @brief CHexenSuppe Spezialisierung von CDrink
 */

class CHexenSuppe : public CDrink
{
public:
    CHexenSuppe();

    virtual ~CHexenSuppe() override;
    virtual double getAlkoholPegel() const override;


};

#endif // CHEXENSUPPE_H
