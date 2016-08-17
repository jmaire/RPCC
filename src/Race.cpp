#include <algorithm>
#include "Race.h"

Race::Race(std::string id, std::string name)
: Data(id)
, m_name(name)
, m_playable(false)
{}

Race::Race()
: Race(UNDEFINED_ID,"")
{}

Race::~Race()
{}

std::string Race::getName()
{
    return m_name;
}

void Race::setRacePlayable(bool playable)
{
    m_playable = playable;
}

bool Race::isPlayable()
{
    return m_playable;
}

bool Race::haveAttributeLowerBoundary(std::string key)
{
    return m_attributesLowerBoundary.find(key) != m_attributesLowerBoundary.end();
}

bool Race::haveAttributeHigherBoundary(std::string key)
{
    return m_attributesHigherBoundary.find(key) != m_attributesHigherBoundary.end();
}

int Race::getAttributeLowerBoundary(std::string key)
{
    if(!haveAttributeLowerBoundary(key))
        return -1;
    return m_attributesLowerBoundary.at(key);
}

int Race::getAttributeHigherBoundary(std::string key)
{
    if(!haveAttributeHigherBoundary(key))
        return -1;
    return m_attributesHigherBoundary.at(key);
}

void Race::setAttributeLowerBoundary(std::string key, int boundary)
{
    m_attributesLowerBoundary[key] = boundary;
}

void Race::setAttributeHigherBoundary(std::string key, int boundary)
{
    m_attributesHigherBoundary[key] = boundary;
}

void Race::setAttributeBounds(std::string key, int lowerBoundary, int higherBoundary)
{
    setAttributeLowerBoundary(key,lowerBoundary);
    setAttributeHigherBoundary(key,higherBoundary);
}

int Race::getAttributeBonus(std::string key)
{
    if(m_attributesBonus.find(key) == m_attributesBonus.end())
        return 0;
    return m_attributesBonus.at(key);
}

void Race::setAttributeBonus(std::string key, int bonus)
{
    if(0 == bonus)
    {
        if(m_attributesBonus.find(key) != m_attributesBonus.end())
            m_attributesBonus.erase(key);
    }
    else
        m_attributesBonus[key] = bonus;
}

std::vector<std::string> Race::getAvailableClass()
{
    return m_class_restriction;
}

void Race::addAvailableClass(std::string key)
{
    if(std::find(m_class_restriction.begin(), m_class_restriction.end(), key) == m_class_restriction.end())
        m_class_restriction.push_back(key);
}
