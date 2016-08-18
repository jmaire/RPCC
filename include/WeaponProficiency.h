#ifndef WEAPONPROFICIENCY_H
#define WEAPONPROFICIENCY_H

#include "config.h"

class WeaponProficiency
{
    public:
        WeaponProficiency(std::string weaponCategoryID);
        WeaponProficiency();

        virtual ~WeaponProficiency();

        int getActualScore();

        #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
        void setMaxBoundary(int boundary);
        bool isIncrementable();
        bool isDecrementable();
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

        bool increment();
        bool decrement();

        std::string toStringCreation();

    protected:
        std::string m_weaponCategoryID;
        int m_score;

        #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
        int m_maxBoundary;
        #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

};

#endif // WEAPONPROFICIENCY_H
