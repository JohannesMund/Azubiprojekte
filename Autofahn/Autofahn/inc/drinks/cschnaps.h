#ifndef CSCHNAPS_H
#define CSCHNAPS_H

#include "cdrink.h"

/**
 * @brief CSchnaps Spezialisierung von CDrink
 */
class CSchnaps : public CDrink
{
public:
    CSchnaps();

    virtual ~CSchnaps() override;
    virtual double getAlkoholPegel() const override;

};

#endif // CSCHNAPS_H
