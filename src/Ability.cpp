#include "Ability.h"

Ability::Ability(std::string id, std::string name)
: Data(id)
, m_name(name)
{}

Ability::Ability()
: Ability(UNDEFINED_ID,"")
{}

Ability::~Ability()
{}

std::string Ability::getName()
{
    return m_name;
}
