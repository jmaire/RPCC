#ifndef ABILITY_H
#define ABILITY_H

#include "config.h"

class Ability
{
    public:
        Ability(std::string nm);
        Ability(void);

        virtual ~Ability(void);

        std::string getName(void);

    protected:
        std::string m_name;

};

#endif // ABILITY_H
