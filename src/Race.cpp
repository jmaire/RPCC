#include <algorithm>
#include "Race.h"

Race::Race(std::string id, std::string nm)
: m_id(id)
, m_name(nm)
{}

Race::Race()
: Race("","")
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

std::vector<Class*> Race::getAvailableClass()
{
    return m_class_restriction;
}

std::pair<int,int> Race::getAttributeBounds(std::string key)
{
    return m_attributesBounds.at(key);
}

void Race::setID(std::string id)
{
    m_id = id;
}

void Race::addAvailableClass(Class* cl)
{
    if(std::find(m_class_restriction.begin(), m_class_restriction.end(), cl) == m_class_restriction.end())
    {
        m_class_restriction.push_back(cl);
    }
}

void Race::setAttributeBounds(std::string key, int lb, int hb)
{
    m_attributesBounds[key] = std::make_pair(lb,hb);
}

