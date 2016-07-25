#include <time.h>
#include "CharacterCreator.h"

CharacterCreator::CharacterCreator(void)
{
    srand(time(nullptr));
}

/*virtual*/ CharacterCreator::~CharacterCreator(void)
{}

/*static*/ Character* CharacterCreator::createRandomCharacter(void)
{
    Character *ch = new Character();
    //
    Race *race = allRaceList[rand() % allRaceList.size()];
    ch->setRace(race);
    //
    ch->setGender((Gender)(rand()%2));
    //
    std::vector<Class*>* availableClass = race->getAvailableClass();
    Class *cla = availableClass->at(rand() % availableClass->size());
    ch->setClass(cla);
    //
    ch->setName("Juju");

    return ch;
}
