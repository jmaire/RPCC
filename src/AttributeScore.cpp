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

int AttributeScore::getPointCost()
{
    #if ATTRIBUTES_NON_CONSTANT_COST == 1
        return ATTRIBUTES_COST[m_score-ATTRIBUTE_DEFAULT_LOW_BOUNDARY];
    #else
        return 1;
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

bool AttributeScore::isIncreasable()
{
    return m_score<m_bounds.second;
}

void AttributeScore::increasePoint(int p)
{
    m_score += p;
}
