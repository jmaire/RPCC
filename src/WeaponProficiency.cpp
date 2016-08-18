#include "DataManager.h"
#include "WeaponCategory.h"
#include "WeaponProficiency.h"

WeaponProficiency::WeaponProficiency(std::string weaponCategoryID)
: m_weaponCategoryID(weaponCategoryID)
, m_score(0)
#ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
, m_maxBoundary(WEAPON_PROFICIENCY_MAX_BOUNDARY)
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
{}

WeaponProficiency::WeaponProficiency()
: WeaponProficiency(UNDEFINED_ID)
{}

WeaponProficiency::~WeaponProficiency()
{}

int WeaponProficiency::getActualScore()
{
    return m_score;
}

#ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
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
    return m_score >= 1;
}
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

bool WeaponProficiency::increment()
{
    #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    if(!isIncrementable())
        return false;
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    m_score++;
    return true;
}

bool WeaponProficiency::decrement()
{
    #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    if(!isDecrementable())
        return false;
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    m_score--;
    return true;
}

std::string WeaponProficiency::toStringCreation()
{
    std::string str = "{" + m_weaponCategoryID + "}:";

    char buff[16];
    sprintf(buff," %d -",getActualScore());
    str += buff;

    WeaponCategory* wc = DataManager::getWeaponCategoryByKey(m_weaponCategoryID);
    if(nullptr != wc)
        str += wc->getName();

    return str;
}
