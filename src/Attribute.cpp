#include "Attribute.h"

Attribute::Attribute(unsigned int sc)
: m_score(sc)
{}

Attribute::Attribute(void)
: Attribute(0)
{}

/*virtual*/ Attribute::~Attribute(void)
{}

unsigned int Attribute::getScore(void)
{
    return m_score;
}

void Attribute::setScore(unsigned int sc)
{
    m_score = sc;
}

void Attribute::incrementScore(void)
{
    m_score++;
}

void Attribute::decrementScore(void)
{
    m_score--;
}

