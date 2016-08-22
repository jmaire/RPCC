#include "WeaponProficiencySet.h"

namespace rpcc
{
    WeaponProficiencySet::WeaponProficiencySet(std::vector<std::string> a_weaponID)
    : CharacteristicSet(a_weaponID)
    , m_unassignedPoints(0)
    #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    , m_maxBoundary(WEAPON_PROFICIENCY_MAX_BOUNDARY)
    #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    {}

    WeaponProficiencySet::WeaponProficiencySet()
    : WeaponProficiencySet(std::vector<std::string>())
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

        m_unassignedPoints = cl->getStartingWeaponProficiency();
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
        return m_csMap.at(id).getActualScore() < m_maxBoundary;
        #else
        return m_csMap.at(id).isIncrementable();
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    }

    bool WeaponProficiencySet::isDecrementable(std::string id)
    {
        if(!isKeyUsed(id))
            return false;
        #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
        return m_csMap.at(id).getActualScore() > 0;
        #else
        return m_csMap.at(id).isDecrementable();
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    }

    void WeaponProficiencySet::incrementByID(std::string id)
    {
        if(m_unassignedPoints>=1 && isIncrementable(id))
            if(m_csMap.at(id).incrementScore())
                m_unassignedPoints--;
    }

    void WeaponProficiencySet::decrementByID(std::string id)
    {
        if(isDecrementable(id))
            if(m_csMap.at(id).decrementScore())
                m_unassignedPoints++;
    }

    std::string WeaponProficiencySet::toStringCreation()
    {
        std::string str = "";
        for(std::map<std::string,WeaponProficiency>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
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
}
