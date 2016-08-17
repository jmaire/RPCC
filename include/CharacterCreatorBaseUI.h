#ifndef CHARACTERCREATORBASEUI_H
#define CHARACTERCREATORBASEUI_H

#include "CharacterCreator.h"

class CharacterCreatorBaseUI
{
    public:
        virtual ~CharacterCreatorBaseUI();

        static void selectRace(Character* ch);

    protected:
        CharacterCreatorBaseUI();
};

#endif // CHARACTERCREATORBASEUI_H
