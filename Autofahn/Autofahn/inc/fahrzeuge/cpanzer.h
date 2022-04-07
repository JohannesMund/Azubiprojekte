#ifndef PANZER_H
#define PANZER_H

#include "cfahrzeug.h"


/**
 * @brief CPanzer Spezialisierung von CFahrzeug
 * @remark Ein Panzer fasst 8 Personen und gilt als schnell mit 30 km/h
 */

class CPanzer : public CFahrzeug
{
public:
    //Konstruktor
    CPanzer();

    bool IsSchnell() const override;
    bool IsVoll() const override;

};

#endif // PANZER_H
