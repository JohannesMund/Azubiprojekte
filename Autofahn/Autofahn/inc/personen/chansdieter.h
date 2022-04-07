#ifndef CHANSDIETER_H
#define CHANSDIETER_H

#include "cperson.h"

/**
 * @brief CHansDieter ist echt trinkfest
 */

class CHansDieter : public CPerson
{
public:
    CHansDieter();

    virtual ~CHansDieter() override;


    /**
     * @brief drink überschrieben von CPerson. Implementiert die herausragende Alkoholtoleranz
     * @param getraenk das zu trinkende Getränk
     */
    virtual void drink(const CDrink* getraenk) override;

};

#endif // CHANSDIETER_H
