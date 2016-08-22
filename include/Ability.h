#ifndef ABILITY_H
#define ABILITY_H

#include "Data.h"

namespace rpcc
{
    class Ability : public Data
    {
        public:
            Ability(std::string id, std::string name);
            Ability();

            virtual ~Ability();

            std::string getName();

        protected:
            std::string m_name, m_description;

    };
}

#endif // ABILITY_H
