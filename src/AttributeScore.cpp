#include "AttributeScore.h"
#include "DataManager.h"

AttributeScore::AttributeScore(std::string key)
: m_key(key)
, m_score(ATTRIBUTE_NEUTRAL_SCORE)
, m_bonus(0)
, m_bounds(std::make_pair(ATTRIBUTE_DEFAULT_LOW_BOUNDARY,ATTRIBUTE_DEFAULT_HIGH_BOUNDARY))
{}

AttributeScore::AttributeScore()
: AttributeScore("")
{}

AttributeScore::~AttributeScore()
{}

int AttributeScore::getActualScore()
{
    return m_score + m_bonus;
}

void AttributeScore::setBonus(int b)
{
    m_bonus = b;
}

void AttributeScore::setBounds(Race* rc, Class* cl)
{
    std::pair<int,int> rcBounds = rc->getAttributeBounds(m_key);
    std::pair<int,int> clBounds = cl->getAttributeBounds(m_key);
    m_bounds.first = MY_MAX(rcBounds.first,clBounds.first);
    m_bounds.second = MY_MAX(rcBounds.second,clBounds.second);
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

std::string AttributeScore::toString()
{
    std::string str = "{" + m_key + "}";

    Attribute* att = DataManager::getAttributeByKey(m_key);
    if(nullptr != att)
        str += " " + att->getName();

    char buff[16];
    sprintf(buff," [%d;%d]",m_bounds.first,m_bounds.second);
    str += buff;

    sprintf(buff," (%d + %d) = %d",m_score,m_bonus,getActualScore());
    str += buff;

    return str;
}

