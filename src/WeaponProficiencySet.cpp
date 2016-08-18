#include "WeaponProficiencySet.h"

WeaponProficiencySet::WeaponProficiencySet(std::vector<std::string> a_weaponID)
: m_unassignedPoints(0)
{
    for(unsigned int i=0; i<a_weaponID.size(); i++)
        m_wpMap[a_weaponID[i]] = new WeaponProficiency(a_weaponID[i]);
}

WeaponProficiencySet::WeaponProficiencySet()
: WeaponProficiencySet(std::vector<std::string>())
{}

WeaponProficiencySet::~WeaponProficiencySet()
{}
