#ifndef CHARACTER_H
#define CHARACTER_H

#include "AttributesSet.h"
#include "Class.h"
#include "Race.h"
#include "TraitsSet.h"
#include "WeaponProficiencySet.h"

enum class Gender
{
	FEMALE = 0,
	MALE = 1,
	GENDER_SIZE
};

static const std::string GENDER_NAME[(unsigned int)Gender::GENDER_SIZE] = {"Female","Male"};

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
        bool isAttributesSetValid();
        bool isNameValid();

        void setName(std::string nm);
        void setRace(Race* rc);
        void setGender(Gender gd);
        void setClass(Class* cl);

        void initAttributes();
        AttributesSet* getAttributesSet();

        void initWeaponProficiency();
        WeaponProficiencySet* getWeaponProficiencySet();

        std::vector<std::string> getAvailableClass();

        std::string toString();

    protected:
        CharacterCreationStep m_creationStep;

        std::string m_name;
        std::string m_portraitPath;
        //unsigned int m_level;
        //unsigned int m_experience;

        Race* m_race;
        Gender m_gender;
        Class* m_class;
        AttributesSet m_attributesSet;
        WeaponProficiencySet m_wpSet;
        TraitsSet m_traitsSet;
};

#endif // CHARACTER_H
