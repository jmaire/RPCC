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

bool Class::haveAttributeLowBoundary(std::string key)
{
    return m_attributesLowBoundary.find(key) != m_attributesLowBoundary.end();
}

int Class::getAttributeLowBoundary(std::string key)
{
    if(!haveAttributeLowBoundary(key))
        return -1;
    return m_attributesLowBoundary.at(key);
}

void Class::setAttributeLowBoundary(std::string key, int boundary)
{
    m_attributesLowBoundary[key] = boundary;
}

