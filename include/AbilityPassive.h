#ifndef ABILITYPASSIVE_H
#define ABILITYPASSIVE_H

#include "Ability.h"

class AbilityPassive : public Ability
{
    public:
        AbilityPassive(std::string id, std::string name);
        AbilityPassive();

        virtual ~AbilityPassive();

    protected:

};

#endif // ABILITYPASSIVE_H
