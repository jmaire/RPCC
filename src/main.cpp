#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "DataLoader.h"
//#include "Dice.h"

int main(int argc, char* argv[])
{
    DataLoader::load();
    //Race* r = DataManager::getRaceByKey("elf");
    //std::cout << "::" << r->getName() << "\n";
    //Class* c = DataManager::getClassByKey("thief");


    AttributesSet ass = AttributesSet();

    for(int i=0; i<5; i++)
    {
        std::cout << "\n-----------------------------\n" << ass.toString() << "\n";
        //std::cout << "\n augmentable? " << ass.isIncreasable(1);
        ass.incrementPoint("dex");
    }
}
