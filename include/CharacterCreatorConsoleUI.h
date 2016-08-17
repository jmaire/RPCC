#ifndef CHARACTERCREATORCONSOLEUI_H
#define CHARACTERCREATORCONSOLEUI_H

#include "CharacterCreatorBaseUI.h"

class CharacterCreatorConsoleUI : public CharacterCreatorBaseUI
{
    public:
        virtual ~CharacterCreatorConsoleUI();

        static void selectRace(Character* ch);

    private:
        CharacterCreatorConsoleUI();
};

#endif // CHARACTERCREATORCONSOLEUI_H
