#ifndef WEAPONPROFICIENCYSET_H
#define WEAPONPROFICIENCYSET_H

#include <vector>
#include "CharacteristicSet.h"
#include "Class.h"
#include "WeaponProficiency.h"

namespace rpcc
{
    class WeaponProficiencySet : public CharacteristicSet<WeaponProficiency>
    {
        public:
            WeaponProficiencySet(std::vector<std::string> a_weaponID);
            WeaponProficiencySet();

            virtual ~WeaponProficiencySet();

            void setWeaponProficiencyMaxBoundary(Class* cl);

            #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            void setMaxBoundary(int boundary);
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

            bool isIncrementable(std::string id);
            bool isDecrementable(std::string id);

            void incrementByID(std::string id);
            void decrementByID(std::string id);

            std::string toStringCreation();

        protected:
            //std::map<std::string,WeaponProficiency> m_wpMap;
            int m_unassignedPoints;

            #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            int m_maxBoundary;
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
    };
}

#endif // WEAPONPROFICIENCYSET_H
