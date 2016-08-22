#ifndef CLASS_H
#define CLASS_H

#include <map>
#include <vector>
#include "Data.h"

namespace rpcc
{
    class Class : public Data
    {
        public:
            Class(std::string id, std::string name);
            Class();

            virtual ~Class();

            std::string getName();

            bool haveAttributeLowBoundary(std::string key);
            int getAttributeLowBoundary(std::string key);
            void setAttributeLowBoundary(std::string key, int boundary);

            std::vector<std::string> getAvailableWC();
            void addAvailableWC(std::string id);

            #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            int getWeaponProficiencyMaxBoundary();
            void setWeaponProficiencyMaxBoundary(int boundary);
            #else
            bool haveWeaponProficiencyMaxBoundary(std::string key);
            int getWeaponProficiencyMaxBoundary(std::string key);
            void setWeaponProficiencyMaxBoundary(std::string key, int boundary);
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

            void setStartingWeaponProficiency(unsigned int swp);
            unsigned int getStartingWeaponProficiency();

        protected:
            std::string m_name;
            std::map<std::string,int> m_attributesLowBoundary;
            std::vector<std::string> m_weaponCategoryAvailable;
            #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            int m_weaponProficiencyMaxBoundary;
            #else
            std::map<std::string,int> m_weaponProficiencyMaxBoundary;
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

            unsigned int m_startingWP;
    };
}

#endif // CLASS_H
