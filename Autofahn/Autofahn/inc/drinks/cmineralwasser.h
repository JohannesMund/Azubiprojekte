#ifndef CMINERALWASSER_H
#define CMINERALWASSER_H

#include "cdrink.h"

/**
 * @brief CMineralWasser Spezialisierung von CDrink
 */
class CMineralWasser : public CDrink
{
public:
    CMineralWasser();

    virtual ~CMineralWasser() override;
    virtual double getAlkoholPegel() const override;
};

#endif // CMINERALWASSER_H
