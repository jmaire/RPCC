#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#if USED_UI == CONSOLE_UI
#include "CharacterCreatorConsoleUI.h"
#elif USED_UI == WINDOWS_GUI
#include "CharacterCreatorWindowsGUI.h"
#endif // USED_UI

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
            static void goToNextStep(Character *ch);

            #if USED_UI == WINDOWS_GUI
            static void setMainParameters(HINSTANCE hInst, HINSTANCE hPrevInst, char * cmdParam, int cmdShow);
            #endif // USED_UI

        protected:
            #if USED_UI == CONSOLE_UI
            static CharacterCreatorConsoleUI m_ui;
            #elif USED_UI == WINDOWS_GUI
            static CharacterCreatorWindowsGUI m_ui;
            #endif // USED_UI

        private:
            CharacterCreator();
    };
}

#endif // CHARACTERCREATOR_H
