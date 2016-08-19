#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "CharacteristicSet.h"
#include "DataLoader.h"

int main(int argc, char* argv[])
{
    DataLoader::loadData();

    /////////////////////////////////////
/*
    Race* r = DataManager::getRaceByKey("elf");
    Class* c = DataManager::getClassByKey("thief");

    AttributesSet ass = AttributesSet();
    ass.setAttributeBonus(r);
    ass.setAttributeBounds(r,c);

    for(int i=0; i<5; i++)
    {
        std::cout << "\n-----------------------------\n" << ass.toString() << "\n";
        //std::cout << "\n augmentable? " << ass.isIncreasable(1);
        ass.incrementPoint("dex");
    }*/
    Character *ch = CharacterCreator::createCharacter();

    std::cout << "\n" << ch->toString();
}
