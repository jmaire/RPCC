#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CharacterCreator.h"
#include "CharacteristicSet.h"
#include "DataLoader.h"

using namespace rpcc;

#if USED_UI == WINDOWS_GUI
#include <windows.h>
#include "CharacterCreatorWindowsGUI.h"
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char * cmdParam, int cmdShow)
#else
int main(int argc, char* argv[])
#endif // USED_UI
{
    DataLoader::loadData();

    #if USED_UI == WINDOWS_GUI
    CharacterCreator::setMainParameters(hInst,hPrevInst,cmdParam,cmdShow);
    MSG  msg;
    int status;

    while ((status = ::GetMessage(&msg,0,0,0)) != 0)
    {
        if (-1 == status)
            return -1;
        ::DispatchMessage(&msg);
    }
    #endif // USED_UI

    Character *ch = CharacterCreator::createCharacter();

    std::cout << "\n" << ch->toString();

    #if USED_UI == WINDOWS_GUI
    return msg.wParam;
    #else
    return 0;
    #endif // USED_UI
}
