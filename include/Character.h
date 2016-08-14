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
        Character();

        virtual ~Character();

        CharacterCreationStep getCreationStep();
        void goToNextCreationStep();
        bool isRaceValid();
        bool isGenderValid();
        bool isClassValid();

        void setName(std::string nm);
        void setRace(Race* rc);
        void setGender(Gender gd);
        void setClass(Class* cl);

        std::vector<Class*> getAvailableClass();

        std::string toString();

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
