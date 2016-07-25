#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Character.h"
#include "Dice.h"

int main(int argc, char* argv[])
{
    Ability ab1 = Ability("Bravoure");
    Ability ab2 = Ability("Fuyard");
    Ability ab3 = Ability("Témérité");
    Ability ab4 = Ability("Lâcheté");

    Trait tr1 = Trait("Courageux","Prudent");
    tr1.addAbility(-25,&ab1);
    tr1.addAbility(25,&ab2);
    tr1.addAbility(-75,&ab3);
    tr1.addAbility(75,&ab4);

    TraitScore ts1 = TraitScore(&tr1,50);

    std::vector<Ability*> abs = ts1.getKnownAbilities();

    for(std::vector<Ability*>::iterator it = abs.begin() ; it != abs.end(); ++it)
    {
        std::cout << (*it)->getName() << "\n";
    }

}
