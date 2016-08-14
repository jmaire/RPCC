#include <algorithm>
#include "Race.h"

Race::Race(std::string id, std::string name)
: m_id(id)
, m_name(name)
{}

Race::Race()
: Race(UNDEFINED_ID,"")
{}

/*virtual*/ Race::~Race()
{}

std::string Race::getID()
{
    return m_id;
}

std::string Race::getName()
{
    return m_name;
}

std::vector<std::string> Race::getAvailableClass()
{
    return m_class_restriction;
}

std::pair<int,int> Race::getAttributeBounds(std::string key)
{
    return m_attributesBounds.at(key);
}

int Race::getAttributeBonus(std::string key)
{
    return m_attributesBonus.at(key);
}

void Race::setIDToUndefined()
{
    m_id = UNDEFINED_ID;
}

void Race::addAvailableClass(std::string key)
{
    if(std::find(m_class_restriction.begin(), m_class_restriction.end(), key) == m_class_restriction.end())
        m_class_restriction.push_back(key);
}

void Race::setAttributeBounds(std::string key, int lb, int hb)
{
    m_attributesBounds[key] = std::make_pair(lb,hb);
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

