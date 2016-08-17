#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include "Character.h"
#include "DataManager.h"

class CharacterCreator
{
    public:
        virtual ~CharacterCreator();

        //static Character* createCharacter(void);
        static void doStep(Character *ch);
        static bool validStep(Character *ch);
        static void goToNextStep(Character *ch);

    private:
        CharacterCreator();

};

#endif // CHARACTERCREATOR_H
