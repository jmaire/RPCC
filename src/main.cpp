#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "DataManager.h"
#include "Dice.h"

int main(int argc, char* argv[])
{
    DataManager::load();

    //Race* r = DataManager::getRaceByKey("elf");
    //Class* c = DataManager::getClassByKey("thief");

    /*
    AttributeScore as = AttributeScore();
    for(int i=0; i<10; i++)
    {
        char buff[16];
        sprintf(buff,"%d",as.getActualScore());
        std::cout << "\n-----------------------------\nValue: " << buff;
        std::cout << "\n augmentable? " << as.isIncreasable();
        as.increasePoint(1);
    }
    */

    AttributesSet ass = AttributesSet();

    for(int i=0; i<5; i++)
    {
        std::cout << "\n-----------------------------\n" << ass.toString() << "\n";
        //std::cout << "\n augmentable? " << ass.isIncreasable(1);
        ass.incrementPoint(1);
    }
}
