#include "WeaponProficiency.h"

WeaponProficiency::WeaponProficiency(std::string weaponCategoryID)
: m_weaponCategoryID(weaponCategoryID)
, m_score(0)
, m_maxBoundary(WEAPON_PROFICIENCY_MAX_BOUNDARY)
{}

WeaponProficiency::WeaponProficiency()
: WeaponProficiency(UNDEFINED_ID)
{}

WeaponProficiency::~WeaponProficiency()
{}

void WeaponProficiency::setMaxBoundary(int boundary)
{
    m_maxBoundary = boundary;
}

bool WeaponProficiency::isIncrementable()
{
    return m_score < m_maxBoundary;
}

bool WeaponProficiency::isDecrementable()
{
    return m_score > 0;
}

void WeaponProficiency::increasePoint(int p)
{
    m_score += p;
}
