#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include "data.h"
#include "Character.h"

class CharacterCreator
{
    public:
        virtual ~CharacterCreator(void);

        //static Character* createCharacter(void);
        static Character* createRandomCharacter(void);

    private:
        CharacterCreator(void);

};

#endif // CHARACTERCREATOR_H
