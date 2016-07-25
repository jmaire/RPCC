#ifndef TRAITSSET_H
#define TRAITSSET_H

#include "config.h"
#include "TraitScore.h"

class TraitsSet
{
    public:
        TraitsSet(std::vector<Trait*> trts);
        TraitsSet(void);

        virtual ~TraitsSet(void);

    protected:
        std::vector<TraitScore> m_traits;

};

#endif // TRAITSSET_H
