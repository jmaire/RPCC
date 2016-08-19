#ifndef TRAITSET_H
#define TRAITSET_H

#include "CharacteristicSet.h"
#include "TraitScore.h"

class TraitSet : public CharacteristicSet<TraitScore>
{
    public:
        TraitSet(std::vector<std::string> a_traitID);
        TraitSet();

        virtual ~TraitSet();

    protected:

};

#endif // TRAITSET_H
