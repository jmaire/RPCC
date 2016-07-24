#include "Trait.h"

Trait::Trait(int sc)
: m_score(sc)
{}

Trait::Trait(void)
: Trait(0)
{}

/*virtual*/ Trait::~Trait(void)
{}

int Trait::getScore(void)
{
    return m_score;
}

void Trait::setScore(int sc)
{
    m_score = sc;
}

void Trait::increaseScore(int i)
{
    m_score += i;
}

