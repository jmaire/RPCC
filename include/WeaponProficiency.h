#ifndef WEAPONPROFICIENCY_H
#define WEAPONPROFICIENCY_H

#include "CharacteristicScore.h"

namespace rpcc
{
    class WeaponProficiency : public CharacteristicScore
    {
        public:
            WeaponProficiency(std::string weaponCategoryID);
            WeaponProficiency();

            virtual ~WeaponProficiency();

            #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            void setMaxBoundary(int boundary);
            bool isScoreIncrementable();
            bool isScoreDecrementable();
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

            bool incrementScore();
            bool decrementScore();

            std::string toStringCreation();

        protected:
            std::string m_weaponCategoryID;

            #ifndef WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
            int m_maxBoundary;
            #endif // WEAPON_PROFICIENCY_GLOBAL_BOUNDARY

    };
}

#endif // WEAPONPROFICIENCY_H
