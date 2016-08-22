#if USED_UI == CONSOLE_UI
#ifndef CHARACTERCREATORCONSOLEUI_H
#define CHARACTERCREATORCONSOLEUI_H

#include "CharacterCreatorBaseUI.h"

class CharacterCreatorConsoleUI : public CharacterCreatorBaseUI
{
    public:
        CharacterCreatorConsoleUI();
        virtual ~CharacterCreatorConsoleUI();

        void selectRace(Character* ch);
        void selectGender(Character* ch);
        void selectClass(Character* ch);
        void selectName(Character* ch);

        void setAttributesScore(Character* ch);
        void setWeaponProficiency(Character* ch);
};

#endif // CHARACTERCREATORCONSOLEUI_H
#endif // USED_UI
