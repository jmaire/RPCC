#include "Attribute.h"

Attribute::Attribute(unsigned int s)
: m_score(s)
{}

Attribute::Attribute()
: Attribute(0)
{}

/*virtual*/ Attribute::~Attribute()
{}

unsigned int Attribute::getScore(void)
{
    return m_score;
}

void Attribute::setScore(unsigned int s)
{
    m_score = s;
}

void Attribute::incrementScore(void)
{
    m_score++;
}

void Attribute::decrementScore(void)
{
    m_score--;
}

