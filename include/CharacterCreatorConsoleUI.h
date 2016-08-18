#ifndef CHARACTERCREATORCONSOLEUI_H
#define CHARACTERCREATORCONSOLEUI_H

#include "CharacterCreatorBaseUI.h"

class CharacterCreatorConsoleUI : public CharacterCreatorBaseUI
{
    public:
        virtual ~CharacterCreatorConsoleUI();

        static void selectRace(Character* ch);
        static void selectGender(Character* ch);
        static void selectClass(Character* ch);
        static void selectName(Character* ch);

        static void setAttributesScore(Character* ch);
        static void setWeaponProficiency(Character* ch);

    private:
        CharacterCreatorConsoleUI();
};

#endif // CHARACTERCREATORCONSOLEUI_H
