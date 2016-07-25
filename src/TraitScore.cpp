#include "TraitScore.h"

TraitScore::TraitScore(Trait* tr, int sc)
: m_trait(tr)
, m_score(sc)
{}

TraitScore::TraitScore(Trait* tr)
: TraitScore(tr,0)
{}

TraitScore::TraitScore(void)
: TraitScore(nullptr,0)
{}

/*virtual*/ TraitScore::~TraitScore(void)
{}

int TraitScore::getScore(void)
{
    return m_score;
}

void TraitScore::setScore(int sc)
{
    m_score = sc;
}

void TraitScore::increaseScore(int i)
{
    m_score += i;
}

std::vector<Ability*> TraitScore::getKnownAbilities(void)
{
    return m_trait->getAvailableAbilties(m_score);
}
