#include "Ability.h"

Ability::Ability(std::string nm)
: m_name(nm)
{}

Ability::Ability(void)
: m_name("")
{}

Ability::~Ability(void)
{}

std::string Ability::getName(void)
{
    return m_name;
}
