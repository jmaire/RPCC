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

#ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
int Class::getWeaponProficiencyMaxBoundary()
{
    return m_weaponProficiencyMaxBoundary;
}

void Class::setWeaponProficiencyMaxBoundary(int boundary)
{
    m_weaponProficiencyMaxBoundary = boundary;
}
#else
bool Class::haveWeaponProficiencyMaxBoundary(std::string key)
{
    return m_weaponProficiencyMaxBoundary.find(key) != m_weaponProficiencyMaxBoundary.end();
}

int Class::getWeaponProficiencyMaxBoundary(std::string key)
{
    if(!haveWeaponProficiencyMaxBoundary(key))
        return -1;
    return m_weaponProficiencyMaxBoundary.at(key);
}

void Class::setWeaponProficiencyMaxBoundary(std::string key, int boundary)
{
    m_weaponProficiencyMaxBoundary[key] = boundary;
}
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
