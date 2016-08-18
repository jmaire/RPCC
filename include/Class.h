#ifndef CLASS_H
#define CLASS_H

#include <map>
#include "Data.h"

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

        #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
        int getWeaponProficiencyMaxBoundary();
        void setWeaponProficiencyMaxBoundary(int boundary);
        #else
        bool haveWeaponProficiencyMaxBoundary(std::string key);
        int getWeaponProficiencyMaxBoundary(std::string key);
        void setWeaponProficiencyMaxBoundary(std::string key, int boundary);
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

    protected:
        std::string m_name;
        std::map<std::string,int> m_attributesLowBoundary;
        #ifdef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
        int m_weaponProficiencyMaxBoundary;
        #else
        std::map<std::string,int> m_weaponProficiencyMaxBoundary;
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

};

#endif // CLASS_H
