#include "Ability.h"

Ability::Ability(std::string id, std::string name)
: m_id(id)
, m_name(name)
{}

Ability::Ability()
: m_name(UNDEFINED_ID,"")
{}

Ability::~Ability()
{}

std::string Ability::getName()
{
    return m_name;
}
