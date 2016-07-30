#include "AttributeScore.h"

AttributeScore::AttributeScore()
: m_score(ATTRIBUTE_NEUTRAL_SCORE)
, m_bonus(0)
, m_bounds(std::make_pair(ATTRIBUTE_DEFAULT_LOW_BOUNDARY,ATTRIBUTE_DEFAULT_HIGH_BOUNDARY))
{}

/*virtual*/ AttributeScore::~AttributeScore()
{}

int AttributeScore::getActualScore()
{
    return m_score + m_bonus;
}

int AttributeScore::getPointsCost()
{
    return 1;
}

int AttributeScore::getNextPointCost()
{
    return 1;
}

int AttributeScore::getPreviousPointCost()
{
    #if ATTRIBUTES_NON_CONSTANT_COST == 1
        return -1;//TODO
    #else
        return -1;
    #endif // ATTRIBUTES_NON_CONSTANT_COST
}


void AttributeScore::setBonus(int b)
{
    m_bonus = b;
}

void AttributeScore::setBounds(int min, int max)
{
    m_bounds.first = min;
    m_bounds.second = max;
}

bool AttributeScore::isIncrementable()
{
    return getActualScore() < m_bounds.second;
}

bool AttributeScore::isDecrementable()
{
    return getActualScore() > m_bounds.first;
}

void AttributeScore::increasePoint(int p)
{
    m_score += p;
}
