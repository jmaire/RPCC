#ifndef WEAPONCATEGORY_H
#define WEAPONCATEGORY_H

#include "Data.h"

namespace rpcc
{
    class WeaponCategory : public Data
    {
        public:
            WeaponCategory(std::string id, std::string name);
            WeaponCategory();

            virtual ~WeaponCategory();

            std::string getName();

        protected:
            std::string m_name;
    };
}

#endif // WEAPONCATEGORY_H
