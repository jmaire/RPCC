#include "CharacterCreatorWindowsGUI.h"

LRESULT CALLBACK WindowProcedure(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            ::PostQuitMessage(0);
            return 0;
    }
    return ::DefWindowProc (hwnd, message, wParam, lParam );
}

WinClass::WinClass(WNDPROC winProc, char const * className, HINSTANCE hInst)
{
    _class.style = 0;
    _class.lpfnWndProc = winProc; // window procedure: mandatory
    _class.cbClsExtra = 0;
    _class.cbWndExtra = 0;
    _class.hInstance = hInst;         // owner of the class: mandatory
    _class.hIcon = 0;
    _class.hCursor = ::LoadCursor (0, IDC_ARROW); // optional
    _class.hbrBackground = (HBRUSH) COLOR_BACKGROUND; // optional
    _class.lpszMenuName = 0;
    _class.lpszClassName = className; // mandatory
}

WinClass::WinClass()
{}

WinClass::~WinClass()
{}

void WinClass::Register()
{
    ::RegisterClass(&_class);
}

//////////////////////////////////////////////////////////////////////////

WinMaker::WinMaker()
: _hwnd (0)
{}

WinMaker::WinMaker(char const * caption,char const * className, HINSTANCE hInstance)
{
    _hwnd = ::CreateWindow (
        className,            // name of a registered window class
        caption,              // window caption
        WS_OVERLAPPEDWINDOW,  // window style
        CW_USEDEFAULT,        // x position
        CW_USEDEFAULT,        // y position
        CW_USEDEFAULT,        // witdh
        CW_USEDEFAULT,        // height
        0,                    // handle to parent window
        0,                    // handle to menu
        hInstance,            // application instance
        0);                   // window creation data
}


WinMaker::~WinMaker()
{}

void WinMaker::Show(int cmdShow)
{
    ::ShowWindow(_hwnd, cmdShow);
    ::UpdateWindow(_hwnd);
}

//////////////////////////////////////////////////////////////////////////

CharacterCreatorWindowsGUI::CharacterCreatorWindowsGUI()
: CharacterCreatorBaseUI()
{}

CharacterCreatorWindowsGUI::~CharacterCreatorWindowsGUI()
{}

void CharacterCreatorWindowsGUI::initWindow(HINSTANCE hInst, int cmdShow)
{
    const char* className = "RPCC";

    WinClass winClass = WinClass(WindowProcedure, className, hInst);
    winClass.Register();

    WinMaker win = WinMaker("Role-Play Character Creator", className, hInst);
    win.Show(cmdShow);
}

void CharacterCreatorWindowsGUI::selectRace(Character* ch)
{

}

void CharacterCreatorWindowsGUI::selectGender(Character* ch)
{

}

void CharacterCreatorWindowsGUI::selectClass(Character* ch)
{

}

void CharacterCreatorWindowsGUI::selectName(Character* ch)
{

}

void CharacterCreatorWindowsGUI::setAttributesScore(Character* ch)
{

}

void CharacterCreatorWindowsGUI::setWeaponProficiency(Character* ch)
{

}
