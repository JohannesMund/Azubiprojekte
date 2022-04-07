#ifndef CREDBULL_H
#define CREDBULL_H

#include "cdrink.h"

/**
 * @brief CEnergy Spezialisierung von CDrink
 */

class CEnergy : public CDrink
{
public:
    CEnergy();

    virtual ~CEnergy() override;
    virtual double getAlkoholPegel() const  override;

};

#endif // CREDBULL_H
