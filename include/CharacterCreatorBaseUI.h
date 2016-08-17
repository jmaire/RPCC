#ifndef CHARACTERCREATORBASEUI_H
#define CHARACTERCREATORBASEUI_H

#include "Character.h"
#include "DataManager.h"

class CharacterCreatorBaseUI
{
    public:
        virtual ~CharacterCreatorBaseUI();

        static void selectRace(Character* ch);
        static void selectGender(Character* ch);
        static void selectClass(Character* ch);
        static void selectName(Character* ch);

        static void setAttributesScore(Character* ch);

    protected:
        CharacterCreatorBaseUI();
};

#endif // CHARACTERCREATORBASEUI_H
