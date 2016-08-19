#include "DataManager.h"
#include "WeaponCategory.h"
#include "WeaponProficiency.h"

WeaponProficiency::WeaponProficiency(std::string weaponCategoryID)
: CharacteristicScore()
, m_weaponCategoryID(weaponCategoryID)
#ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
, m_maxBoundary(WEAPON_PROFICIENCY_MAX_BOUNDARY)
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
{}

WeaponProficiency::WeaponProficiency()
: WeaponProficiency(UNDEFINED_ID)
{}

WeaponProficiency::~WeaponProficiency()
{}

#ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
void WeaponProficiency::setMaxBoundary(int boundary)
{
    m_maxBoundary = boundary;
}

bool WeaponProficiency::isScoreIncrementable()
{
    return getActualScore() < m_maxBoundary;
}

bool WeaponProficiency::isScoreDecrementable()
{
    return getActualScore() > 0;
}
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

bool WeaponProficiency::incrementScore()
{
    #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    if(!isIncrementable())
        return false;
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    return increaseScore(1);
}

bool WeaponProficiency::decrementScore()
{
    #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    if(!isDecrementable())
        return false;
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    return increaseScore(-1);
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
