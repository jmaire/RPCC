#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include "CharacterCreatorConsoleUI.h"

namespace rpcc
{
    class CharacterCreator
    {
        public:
            virtual ~CharacterCreator();

            static Character* createCharacter();
            static void doStep(Character *ch);
            static bool validStep(Character *ch);
            static bool isCreationFinish(Character *ch);

        protected:
            static CharacterCreatorConsoleUI m_ui;

            static void goToNextStep(Character *ch);

        private:
            CharacterCreator();
    };
}

#endif // CHARACTERCREATOR_H
