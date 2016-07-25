#include "AttributeScore.h"

AttributeScore::AttributeScore(unsigned int sc)
: m_score(sc)
{}

AttributeScore::AttributeScore(void)
: AttributeScore(0)
{}

/*virtual*/ AttributeScore::~AttributeScore(void)
{}

unsigned int AttributeScore::getScore(void)
{
    return m_score;
}

void AttributeScore::setScore(unsigned int sc)
{
    m_score = sc;
}

void AttributeScore::incrementScore(void)
{
    m_score++;
}

void AttributeScore::decrementScore(void)
{
    m_score--;
}

