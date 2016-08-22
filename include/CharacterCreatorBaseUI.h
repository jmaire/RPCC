#ifndef CHARACTERCREATORBASEUI_H
#define CHARACTERCREATORBASEUI_H

#include "Character.h"
#include "DataManager.h"

namespace rpcc
{
    class CharacterCreatorBaseUI
    {
        public:
            virtual ~CharacterCreatorBaseUI();

            virtual void selectRace(Character* ch)=0;
            virtual void selectGender(Character* ch)=0;
            virtual void selectClass(Character* ch)=0;
            virtual void selectName(Character* ch)=0;

            virtual void setAttributesScore(Character* ch)=0;
            virtual void setWeaponProficiency(Character* ch)=0;

        protected:
            CharacterCreatorBaseUI();
    };
}

#endif // CHARACTERCREATORBASEUI_H
