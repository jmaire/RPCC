#if USED_UI == WINDOWS_GUI
#ifndef CHARACTERCREATORWINDOWSGUI_H
#define CHARACTERCREATORWINDOWSGUI_H

#include <windows.h>
#include "CharacterCreatorBaseUI.h"

namespace rpcc
{
    LRESULT CALLBACK WindowProcedure(HWND, unsigned int, WPARAM, LPARAM);

    class WinClass
    {
        public:
            WinClass(WNDPROC winProc, char const * className, HINSTANCE hInst);
            WinClass();

            virtual ~WinClass();

            void Register();

        private:
            WNDCLASS _class;
    };

    //////////////////////////////////////////////////////////////////////////

    class WinMaker
    {
        public:
            WinMaker();
            WinMaker(char const * caption,char const * className, HINSTANCE hInstance);

            virtual ~WinMaker();

            void Show (int cmdShow);

        protected:
            HWND _hwnd;
    };

    //////////////////////////////////////////////////////////////////////////

    class CharacterCreatorWindowsGUI : public CharacterCreatorBaseUI
    {
        public:
            CharacterCreatorWindowsGUI();
            virtual ~CharacterCreatorWindowsGUI();

            void initWindow(HINSTANCE hInst, int cmdShow);

            void selectRace(Character* ch);
            void selectGender(Character* ch);
            void selectClass(Character* ch);
            void selectName(Character* ch);

            void setAttributesScore(Character* ch);
            void setWeaponProficiency(Character* ch);
    };
}

#endif // CHARACTERCREATORWINDOWSGUI_H
#endif // USED_UI
