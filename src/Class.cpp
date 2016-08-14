#include <algorithm>
#include "Class.h"

Class::Class(std::string id, std::string name)
: m_id(id)
, m_name(name)
{}

Class::Class()
: Class("","")
{}

Class::~Class()
{}

std::string Class::getID()
{
    return m_id;
}

std::string Class::getName()
{
    return m_name;
}

std::pair<int,int> Class::getAttributeBounds(std::string key)
{
    return m_attributesBounds.at(key);
}

void Class::setID(std::string id)
{
    m_id = id;
}

void Class::setAttributeBounds(std::string key, int lb, int hb)
{
    m_attributesBounds[key] = std::make_pair(lb,hb);
}

