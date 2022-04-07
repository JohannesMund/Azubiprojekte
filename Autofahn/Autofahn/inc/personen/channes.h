#ifndef CHANNES_H
#define CHANNES_H

#include "cperson.h"
#include "cdrink.h"


/**
 * @brief CHannes ist eine Spassbremse was Alkohol anbetrifft und erträgt kein RedBull
 */

class CHannes : public CPerson
{
public:
    CHannes();
    virtual ~CHannes() override;

    /**
     * @brief drink überschrieben von CPerson. Implementiert Sonderbehandlungen bei bestimmten Getränken
     * @param getraenk das zu trinkende Getränk
     */
    virtual void drink(const CDrink* getraenk) override;
};

#endif // CHANNES_H
