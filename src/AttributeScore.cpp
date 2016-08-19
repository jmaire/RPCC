#include "tools.h"
#include "Attribute.h"
#include "AttributeScore.h"
#include "DataManager.h"

AttributeScore::AttributeScore(std::string attributeID)
: CharacteristicScore(ATTRIBUTE_NEUTRAL_SCORE)
, m_attributeID(attributeID)
, m_bonus(0)
, m_bounds(std::make_pair(ATTRIBUTE_DEFAULT_LOW_BOUNDARY,ATTRIBUTE_DEFAULT_HIGH_BOUNDARY))
{}

AttributeScore::AttributeScore()
: AttributeScore(UNDEFINED_ID)
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

void AttributeScore::setBounds(int lowerBoundary, int higherBoundary)
{
    m_bounds.first = lowerBoundary;
    m_bounds.second = higherBoundary;
}

bool AttributeScore::isIncrementable()
{
    return getActualScore() < m_bounds.second;
}

bool AttributeScore::isDecrementable()
{
    return getActualScore() > m_bounds.first;
}

bool AttributeScore::incrementScore()
{
    if(!isIncrementable())
        return false;
    return increaseScore(1);
}

bool AttributeScore::decrementScore()
{
    if(!isDecrementable())
        return false;
    return increaseScore(-1);
}

std::string AttributeScore::toString()
{
    std::string str = "{" + m_attributeID + "}";

    Attribute* att = DataManager::getAttributeByKey(m_attributeID);
    if(nullptr != att)
        str += " " + att->getName();

    char buff[16];
    sprintf(buff," [%d;%d]",m_bounds.first,m_bounds.second);
    str += buff;

    sprintf(buff," (%d + %d) = %d",m_score,m_bonus,getActualScore());
    str += buff;

    return str;
}

std::string AttributeScore::toStringCreation()
{
    std::string str = "{" + m_attributeID + "}:";

    char buff[16];
    sprintf(buff," %d -",getActualScore());
    str += buff;

    Attribute* att = DataManager::getAttributeByKey(m_attributeID);
    if(nullptr != att)
        str += att->getName();

    sprintf(buff," [%d;%d]",m_bounds.first,m_bounds.second);
    str += buff;

    return str;
}
