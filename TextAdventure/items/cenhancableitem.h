#ifndef CENHANCABLEITEM_H
#define CENHANCABLEITEM_H

#include <citem.h>

class CEnhancableItem : public CItem
{
public:
    CEnhancableItem();

    virtual void enhance();

protected:
    int _level = 0;
};

#endif // CENHANCABLEITEM_H
