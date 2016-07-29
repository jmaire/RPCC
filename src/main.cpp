#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "DataManager.h"
#include "Dice.h"

int main(int argc, char* argv[])
{
    DataManager::load();

    Race* r = DataManager::getRaceByKey("elf");
    Class* c = DataManager::getClassByKey("thief");

    AttributesSet ass = AttributesSet(r,c);


    for(int i=0; i<5; i++)
    {
        std::cout << "\n-----------------------------\n" << ass.toString();
        std::cout << "\n augmentable? " << ass.isIncreasable(1);
        ass.addPoint(1);
    }
}
