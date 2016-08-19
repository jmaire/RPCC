#ifndef TRAITSSET_H
#define TRAITSSET_H

#include "CharacteristicSet.h"
#include "TraitScore.h"

class TraitsSet : public CharacteristicSet<TraitScore>
{
    public:
        TraitsSet(std::vector<std::string> a_traitID);
        TraitsSet();

        virtual ~TraitsSet();

    protected:

};

#endif // TRAITSSET_H
