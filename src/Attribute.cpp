#include "Attribute.h"

Attribute::Attribute(std::string id, std::string name)
: Data(id)
, m_name(name)
, m_description("")
{}

Attribute::Attribute()
: Attribute(UNDEFINED_ID,"")
{}

Attribute::~Attribute()
{}

std::string Attribute::getName()
{
    return m_name;
}
