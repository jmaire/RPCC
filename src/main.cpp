#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "CharacteristicSet.h"
#include "DataLoader.h"

using namespace rpcc;

int main(int argc, char* argv[])
{
    DataLoader::loadData();

    Character *ch = CharacterCreator::createCharacter();
    std::cout << "\n" << ch->toString();

    return 0;
}
