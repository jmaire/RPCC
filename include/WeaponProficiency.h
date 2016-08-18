#ifndef WEAPONPROFICIENCY_H
#define WEAPONPROFICIENCY_H

#include "config.h"

class WeaponProficiency
{
    public:
        WeaponProficiency(std::string weaponCategoryID);
        WeaponProficiency();

        virtual ~WeaponProficiency();

        void setMaxBoundary(int boundary);

        bool isIncrementable();
        bool isDecrementable();

        void increasePoint(int p);

    protected:
        std::string m_weaponCategoryID;
        int m_score, m_maxBoundary;

};

#endif // WEAPONPROFICIENCY_H
