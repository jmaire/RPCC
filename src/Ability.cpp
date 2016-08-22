#include "Ability.h"

rpcc::Ability::Ability(std::string id, std::string name)
: Data(id)
, m_name(name)
{}

rpcc::Ability::Ability()
: Ability(UNDEFINED_ID,"")
{}

rpcc::Ability::~Ability()
{}

std::string rpcc::Ability::getName()
{
    return m_name;
}
