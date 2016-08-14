#ifndef ABILITY_H
#define ABILITY_H

#include "config.h"

class Ability
{
    public:
        Ability(std::string id, std::string name);
        Ability();

        virtual ~Ability();

        std::string getName();

    protected:
        std::string m_id, m_name, m_description;

};

#endif // ABILITY_H
