#ifndef TRAIT_H
#define TRAIT_H

#include <vector>
#include "config.h"
#include "Ability.h"


class Trait
{
    public:
        Trait(std::string id, std::string leftL, std::string rightL);
        Trait();

        virtual ~Trait();

        void addAbility(int requiredScore, Ability* ab);

        std::vector<Ability*> getAvailableAbilities(int score);

    protected:
        std::string m_id, m_leftLabel, m_rightLabel;
        std::vector<std::pair<int,Ability*>> m_abilityMap;

};

#endif // TRAIT_H
