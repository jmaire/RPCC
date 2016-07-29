#include <time.h>
#include "CharacterCreator.h"
#include "DataManager.h"

#include "iostream"

CharacterCreator::CharacterCreator(void)
{}

/*virtual*/ CharacterCreator::~CharacterCreator(void)
{}

/*static*/ void doStep(Character *ch)
{
    switch(ch->getCreationStep())
    {
    case START:
        break;

    case RACE_SELECTION:

        break;

    case GENDER_SELECTION:
        break;

    case CLASS_SELECTION:
        break;

    case DONE:
        break;

    default:
        break;
    }


}

/*static*/ bool CharacterCreator::validStep(Character *ch)
{
    bool isValid;

    switch(ch->getCreationStep())
    {
    case START:
        isValid = true;
        break;

    case RACE_SELECTION:
        isValid = ch->isRaceValid();
        break;

    case GENDER_SELECTION:
        isValid = ch->isGenderValid();
        break;

    case CLASS_SELECTION:
        isValid = ch->isClassValid();
        break;

    case DONE:
        isValid = true;
        break;

    default:
        isValid = false;
        break;
    }

    if(isValid)
        ch->goToNextCreationStep();
    return isValid;
}


/*static*/ void CharacterCreator::nextStep(Character *ch)
{

}
