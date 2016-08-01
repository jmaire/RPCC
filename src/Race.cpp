#include <algorithm>
#include "Race.h"

Race::Race(std::string n)
{
    m_name = n;
}

Race::Race()
: Race("#UNDEFINED")
{}

/*virtual*/ Race::~Race()
{}

std::string* Race::getName(void)
{
    return &m_name;
}

std::vector<Class*>* Race::getAvailableClass(void)
{
    return &m_class_restriction;
}

std::pair<int,int> Race::getAttributeBounds(std::string key)
{
    return m_attributesBounds.at(key);
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

