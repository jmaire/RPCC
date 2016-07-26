#ifndef CHARACTER_H
#define CHARACTER_H

#include "AttributesSet.h"
#include "Class.h"
#include "Race.h"
#include "TraitsSet.h"

enum class Gender
{
	FEMALE = 0,
	MALE = 1
};

class Character
{
    public:
        Character(void);

        virtual ~Character(void);

        CharacterCreationStep getCreationStep(void);
        void goToNextCreationStep(void);
        bool isRaceValid(void);
        bool isGenderValid(void);
        bool isClassValid(void);

        void setName(std::string nm);
        void setRace(Race* rc);
        void setGender(Gender gd);
        void setClass(Class* cl);

        std::vector<Class*>* getAvailableClass(void);

        std::string toString(void);

    protected:
        CharacterCreationStep m_creationStep;

        std::string m_name;
        std::string m_portraitPath;
        unsigned int m_level;
        unsigned int m_experience;

        Race* m_race;
        Gender m_gender;
        Class* m_class;
        AttributesSet m_attributes_set;
        TraitsSet m_traits_set;
};

#endif // CHARACTER_H
