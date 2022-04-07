#ifndef AUTO_H
#define AUTO_H

#include "cfahrzeug.h"

/**
 * @brief CAuto Spezialisierung von Fahrzeug
 * @remark ein Auto fasst 5 Personen und gilt ab 150km/h als schnell
 */

class CAuto : public CFahrzeug
{
public:
    CAuto();
    bool IsSchnell() const override;
    bool IsVoll() const override;

private:

};

/**
 * @brief CRotesAuto Spezialisierung von CAuto
 * @remark wie der Name sagt, das Auto ist rot
 */

class CRotesAuto : public CAuto
{
public:

    CRotesAuto();

};

#endif // AUTO_H
