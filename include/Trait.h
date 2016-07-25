#ifndef TRAIT_H
#define TRAIT_H

#include <vector>
#include "config.h"
#include "Ability.h"


class Trait
{
    public:
        Trait(std::string ll, std::string rl);
        Trait(void);

        virtual ~Trait(void);

        void addAbility(int sc, Ability* ab);

        std::vector<Ability*> getAvailableAbilties(int sc);

    protected:
        std::string m_leftLabel, m_rightLabel;
        std::vector<std::pair<int,Ability*>> m_abilityMap;

};

#endif // TRAIT_H
