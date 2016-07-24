#ifndef CHARACTER_H
#define CHARACTER_H

#include "Alignment.h"
#include "AttributesSet.h"
#include "Class.h"
#include "Race.h"

enum class Gender
{
	FEMALE = 0,
	MALE = 1,
	GENDER_COUNT
};

class Character
{
    public:
        Character();
        virtual ~Character();

    protected:
        std::string m_name;
        unsigned int m_level;
        unsigned int m_experience;

        Gender m_gender;
        Race m_race;
        Class m_class;
        Alignment m_alignment;
        AttributesSet m_attributes_set;

};

#endif // CHARACTER_H
