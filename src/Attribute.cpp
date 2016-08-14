#include "Attribute.h"

Attribute::Attribute(std::string id, std::string name)
: m_id(id)
, m_name(name)
, m_description("")
{}

Attribute::Attribute()
: Attribute(UNDEFINED_ID,"")
{}

Attribute::~Attribute()
{}

std::string Attribute::getID()
{
    return m_id;
}

std::string Attribute::getName()
{
    return m_name;
}

void Attribute::setIDToUndefined()
{
    m_id = UNDEFINED_ID;
}

