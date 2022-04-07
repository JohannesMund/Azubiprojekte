#ifndef CBIER_H
#define CBIER_H

#include <string>
#include "cdrink.h"

/**
 * @brief CBier Spezialisierung von CDrink
 */

class CBier : public CDrink
{
public:
    CBier();
    virtual ~CBier() override;
    virtual double getAlkoholPegel() const override;
};

#endif // CBIER_H
