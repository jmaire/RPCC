#include <algorithm>
#include "Class.h"

Class::Class(std::string n)
{
    m_name = n;
}

Class::Class(void)
: Class("#UNDEFINED")
{}

/*virtual*/ Class::~Class(void)
{}

std::string* Class::getName(void)
{
    return &m_name;
}

std::pair<int,int> Class::getAttributeBounds(std::string key)
{
    return m_attributesBounds.at(key);
}

void Class::setAttributeBounds(std::string key, int lb, int hb)
{
    m_attributesBounds[key] = std::make_pair(lb,hb);
}

