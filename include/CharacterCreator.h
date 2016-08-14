#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include "Character.h"

class CharacterCreator
{
    public:
        virtual ~CharacterCreator(void);

        //static Character* createCharacter(void);
        static void doStep(Character *ch);
        static bool validStep(Character *ch);
        static void goToNextStep(Character *ch);

    private:
        CharacterCreator(void);

};

#endif // CHARACTERCREATOR_H
