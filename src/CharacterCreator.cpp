#include "CharacterCreator.h"
#include "DataManager.h"

namespace rpcc
{
    #if USED_UI == CONSOLE_UI
    CharacterCreatorConsoleUI CharacterCreator::m_ui;
    #elif USED_UI == WINDOWS_GUI
    CharacterCreatorWindowsGUI CharacterCreator::m_ui;
    #endif // USED_UI

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
            m_ui.selectRace(ch);
            break;

        case GENDER_SELECTION:
            m_ui.selectGender(ch);
            break;

        case CLASS_SELECTION:
            m_ui.selectClass(ch);
            break;

        case ATTRIBUTES_SETTING:
            m_ui.setAttributesScore(ch);
            break;

        case WEAPONPROFICIENCY_SETTING:
            m_ui.setWeaponProficiency(ch);
            break;

        case NAME_SELECTION:
            m_ui.selectName(ch);
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
            //isValid = ch->isAttributesSetValid();
            isValid = true;
            break;

        case WEAPONPROFICIENCY_SETTING:
            //isValid = ch->isAttributesSetValid();
            isValid = true;
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

    #if USED_UI == WINDOWS_GUI
    void CharacterCreator::setMainParameters(HINSTANCE hInst, HINSTANCE hPrevInst, char * cmdParam, int cmdShow)
    {
        m_ui.initWindow(hInst,cmdShow);
    }
    #endif // USED_UI
}
