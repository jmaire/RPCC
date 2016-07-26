#include <time.h>
#include "CharacterCreator.h"
#include "DataManager.h"

#include "iostream"

CharacterCreator::CharacterCreator(void)
{}

/*virtual*/ CharacterCreator::~CharacterCreator(void)
{}

/*static*/ bool CharacterCreator::validStep(Character* ch)
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


/*static*/ void CharacterCreator::nextStep(Character* ch)
{

}
