#include "CharacterCreator.h"
#include "DataManager.h"

CharacterCreator::CharacterCreator()
{}

CharacterCreator::~CharacterCreator()
{}

void doStep(Character *ch)
{
    switch(ch->getCreationStep())
    {
    case CREATION_START:
        break;

    case RACE_SELECTION:

        break;

    case GENDER_SELECTION:
        break;

    case CLASS_SELECTION:
        break;

    case CREATION_DONE:
        break;

    default:
        break;
    }
}

bool CharacterCreator::validStep(Character *ch)
{
    bool isValid;

    switch(ch->getCreationStep())
    {
    case CREATION_START:
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

    case CREATION_DONE:
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


void CharacterCreator::goToNextStep(Character *ch)
{
    ch->goToNextCreationStep();
}
