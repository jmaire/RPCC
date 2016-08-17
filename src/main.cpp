#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreatorConsoleUI.h"
#include "DataLoader.h"
//#include "Dice.h"

int main(int argc, char* argv[])
{
    DataLoader::load();
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
    Character ch = Character();

    CharacterCreatorConsoleUI::selectRace(&ch);
    CharacterCreatorConsoleUI::selectGender(&ch);
    CharacterCreatorConsoleUI::selectClass(&ch);
    CharacterCreatorConsoleUI::selectName(&ch);
    ch.initAttributes();
    CharacterCreatorConsoleUI::setAttributesScore(&ch);

    std::cout << ch.toString();
}
