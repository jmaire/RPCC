#include <algorithm>
#include "Class.h"

Class::Class(std::string id, std::string name)
: Data(id)
, m_name(name)
{}

Class::Class()
: Class(UNDEFINED_ID,"")
{}

Class::~Class()
{}

std::string Class::getName()
{
    return m_name;
}

std::pair<int,int> Class::getAttributeBounds(std::string key)
{
    if(m_attributesBounds.find(key) == m_attributesBounds.end())
        return std::make_pair(ATTRIBUTE_DEFAULT_LOW_BOUNDARY,ATTRIBUTE_DEFAULT_HIGH_BOUNDARY);
    return m_attributesBounds.at(key);
}

void Class::setAttributeBounds(std::string key, int lb, int hb)
{
    m_attributesBounds[key] = std::make_pair(lb,hb);
}

