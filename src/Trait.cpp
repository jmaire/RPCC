#include "Trait.h"

Trait::Trait(std::string id, std::string leftL, std::string rightL)
: Data(id)
, m_leftLabel(leftL)
, m_rightLabel(rightL)
{}

Trait::Trait()
: Trait("","","")
{}

Trait::~Trait()
{}

void Trait::addAbility(int requiredScore, Ability* ab)
{
    m_abilityMap.push_back(std::make_pair(requiredScore,ab));
}

std::vector<Ability*> Trait::getAvailableAbilities(int score)
{
    std::vector<Ability*> availableAbility;
    for(std::vector<std::pair<int,Ability*>>::iterator it = m_abilityMap.begin() ; it != m_abilityMap.end(); ++it)
        if((double)score/(*it).first>=1.f)
            availableAbility.push_back((*it).second);

    return availableAbility;
}
