#include "Trait.h"

Trait::Trait(std::string ll, std::string rl)
: m_leftLabel(ll)
, m_rightLabel(rl)
{}

Trait::Trait(void)
: Trait(nullptr,nullptr)
{}

Trait::~Trait(void)
{}

void Trait::addAbility(int sc, Ability* ab)
{
    m_abilityMap.push_back(std::make_pair(sc,ab));
}

std::vector<Ability*> Trait::getAvailableAbilities(int sc)
{
    std::vector<Ability*> availableAbility;
    for(std::vector<std::pair<int,Ability*>>::iterator it = m_abilityMap.begin() ; it != m_abilityMap.end(); ++it)
        if((double)sc/(*it).first>=1.f)
            availableAbility.push_back((*it).second);

    return availableAbility;
}
