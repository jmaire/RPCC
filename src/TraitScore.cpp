#include "DataManager.h"
#include "TraitScore.h"

TraitScore::TraitScore(std::string traitID)
: CharacteristicScore()
, m_traitID(traitID)
{}

TraitScore::TraitScore()
: TraitScore(UNDEFINED_ID)
{}

TraitScore::~TraitScore()
{}

std::vector<Ability*> TraitScore::getKnownAbilities()
{
    Trait* trait = DataManager::getTraitByKey(m_traitID);
    if(nullptr == trait)
        return std::vector<Ability*>();

    return trait->getAvailableAbilities(m_score);
}
