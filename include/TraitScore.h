#ifndef TRAITSCORE_H
#define TRAITSCORE_H

#include "CharacteristicScore.h"
#include "Trait.h"

namespace rpcc
{
    class TraitScore : CharacteristicScore
    {
        public:
            TraitScore(std::string traitID);
            TraitScore();

            virtual ~TraitScore();

            std::vector<Ability*> getKnownAbilities();

        protected:
            std::string m_traitID;

    };
}

#endif // TRAITSCORE_H
