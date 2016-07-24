#ifndef TRAITSSET_H
#define TRAITSSET_H

#include "config.h"
#include "Trait.h"

class TraitsSet
{
    public:
        TraitsSet(void);

        virtual ~TraitsSet(void);

    protected:
        Trait ma_traits[TRAITS_SET_SIZE];

};

#endif // TRAITSSET_H
