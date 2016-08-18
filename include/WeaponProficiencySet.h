#ifndef WEAPONPROFICIENCYSET_H
#define WEAPONPROFICIENCYSET_H

#include <map>
#include <vector>

#include "WeaponProficiency.h"

class WeaponProficiencySet
{
    public:
        WeaponProficiencySet(std::vector<std::string> a_weaponID);
        WeaponProficiencySet();

        virtual ~WeaponProficiencySet();

    protected:
        std::map<std::string,WeaponProficiency*> m_wpMap;
        int m_unassignedPoints;
};

#endif // WEAPONPROFICIENCYSET_H
