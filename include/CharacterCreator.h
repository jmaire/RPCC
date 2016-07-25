#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include "Character.h"

class CharacterCreator
{
    public:
        CharacterCreator(void);

        virtual ~CharacterCreator(void);

        void createCharacter(void);

    protected:
        Character* m_character;
};

#endif // CHARACTERCREATOR_H
