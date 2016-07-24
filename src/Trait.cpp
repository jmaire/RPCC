#include "Trait.h"

Trait::Trait(int sc)
: m_score(sc)
{}

Trait::Trait(void)
: Trait(0)
{}

/*virtual*/ Trait::~Trait(void)
{}

unsigned int Trait::getScore(void)
{
    return m_score;
}

void Trait::setScore(unsigned int sc)
{
    m_score = sc;
}
