#ifndef WEAPONCATEGORY_H
#define WEAPONCATEGORY_H

#include "Data.h"

class WeaponCategory : public Data
{
    public:
        WeaponCategory(std::string id);
        WeaponCategory();

        virtual ~WeaponCategory();

        std::string getName();

    protected:
        std::string m_name;

};

#endif // WEAPONCATEGORY_H
