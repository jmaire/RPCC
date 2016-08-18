#include "WeaponProficiencySet.h"

WeaponProficiencySet::WeaponProficiencySet(std::vector<std::string> a_weaponID)
: m_unassignedPoints(8)
#ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
, m_maxBoundary(WEAPON_PROFICIENCY_MAX_BOUNDARY)
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
{
    for(unsigned int i=0; i<a_weaponID.size(); i++)
        m_wpMap[a_weaponID[i]] = WeaponProficiency(a_weaponID[i]);
}

WeaponProficiencySet::WeaponProficiencySet()
//: WeaponProficiencySet(std::vector<std::string>())
: WeaponProficiencySet({"axe","bow","sword"})
{}

WeaponProficiencySet::~WeaponProficiencySet()
{}

void WeaponProficiencySet::setWeaponProficiencyMaxBoundary(Class* cl)
{
    #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    setMaxBoundary(cl->getWeaponProficiencyMaxBoundary());
    #else
    for(std::map<std::string,WeaponProficiency>::iterator it=m_wpMap.begin(); it!=m_wpMap.end(); ++it)
    {
        if(cl->haveWeaponProficiencyMaxBoundary(it->first))
            it->second.setMaxBoundary(cl->getWeaponProficiencyMaxBoundary(it->first));
    }
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
}

bool WeaponProficiencySet::isKeyUsed(std::string id)
{
    return m_wpMap.find(id) != m_wpMap.end();
}

#ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
void WeaponProficiencySet::setMaxBoundary(int boundary)
{
    m_maxBoundary = boundary;
}
#endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

bool WeaponProficiencySet::isIncrementable(std::string id)
{
    if(!isKeyUsed(id))
        return false;
    #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    return m_wpMap.at(id).getActualScore() < m_maxBoundary;
    #else
    return m_wpMap.at(id).isIncrementable();
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
}

bool WeaponProficiencySet::isDecrementable(std::string id)
{
    if(!isKeyUsed(id))
        return false;
    #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    return m_wpMap.at(id).getActualScore() > 0;
    #else
    return m_wpMap.at(id).isDecrementable();
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
}

void WeaponProficiencySet::incrementByID(std::string id)
{
    if(m_unassignedPoints>=1 && isIncrementable(id))
        if(m_wpMap.at(id).increment())
            m_unassignedPoints--;
}

void WeaponProficiencySet::decrementByID(std::string id)
{
    if(isDecrementable(id))
        if(m_wpMap.at(id).decrement())
            m_unassignedPoints++;
}

std::string WeaponProficiencySet::toStringCreation()
{
    std::string str = "";
    for(std::map<std::string,WeaponProficiency>::iterator it=m_wpMap.begin(); it!=m_wpMap.end(); ++it)
    {
        if(isDecrementable(it->first))
            str += "[-/";
        else
            str += "[ /";

        if(isIncrementable(it->first))
            str += "+]";
        else
            str += " ]";

        str += it->second.toStringCreation() + "\n";
    }

    char buff[16];
    sprintf(buff,"\t|> Unassigned: %d",m_unassignedPoints);
    str += buff;

    return str;
}

