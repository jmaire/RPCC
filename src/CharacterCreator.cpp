#include "CharacterCreator.h"
#include "DataManager.h"

CharacterCreator::CharacterCreator()
{}

CharacterCreator::~CharacterCreator()
{}

Character* CharacterCreator::createCharacter()
{
    Character *ch = new Character();
    while(!isCreationFinish(ch))
    {
        doStep(ch);
        validStep(ch);
    }
    return ch;
}

void CharacterCreator::doStep(Character *ch)
{
    switch(ch->getCreationStep())
    {
    case CREATION_START:
        break;

    case RACE_SELECTION:
#if 1 == USE_CONSOLE_UI
        CharacterCreatorConsoleUI::selectRace(ch);
#endif // USE_CONSOLE_UI
        break;

    case GENDER_SELECTION:
#if 1 == USE_CONSOLE_UI
        CharacterCreatorConsoleUI::selectGender(ch);
#endif // USE_CONSOLE_UI
        break;

    case CLASS_SELECTION:
#if 1 == USE_CONSOLE_UI
        CharacterCreatorConsoleUI::selectClass(ch);
#endif // USE_CONSOLE_UI
        break;

    case ATTRIBUTES_SETTING:
#if 1 == USE_CONSOLE_UI
        CharacterCreatorConsoleUI::setAttributesScore(ch);
#endif // USE_CONSOLE_UI
        break;

    case NAME_SELECTION:
#if 1 == USE_CONSOLE_UI
        CharacterCreatorConsoleUI::selectName(ch);
#endif // USE_CONSOLE_UI
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

    case ATTRIBUTES_SETTING:
        isValid = ch->isAttributesSetValid();
        break;

    case NAME_SELECTION:
        isValid = ch->isNameValid();
        break;

    default:
        isValid = false;
        break;
    }

    if(isValid)
        ch->goToNextCreationStep();
    return isValid;
}

bool CharacterCreator::isCreationFinish(Character *ch)
{
    return ch->getCreationStep() == CREATION_DONE;
}

void CharacterCreator::goToNextStep(Character *ch)
{
    ch->goToNextCreationStep();
}
