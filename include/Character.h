#ifndef CHARACTER_H
#define CHARACTER_H

#include "Alignment.h"
#include "AttributesSet.h"
#include "Class.h"
#include "Race.h"
#include "TraitsSet.h"

enum class Gender
{
	FEMALE = 0,
	MALE = 1,
	GENDER_COUNT
};

class Character
{
    public:
        Character(void);
        virtual ~Character(void);

        void setName(std::string nm);
        void setRace(Race* rc);
        void setGender(Gender gd);
        void setClass(Class* cl);
        void setAlignment(Alignment* al);

        std::vector<Class*> getAvailableClass(void);
        std::vector<Alignment*> getAvailableAlignment(void);

    protected:
        std::string m_name;
        unsigned int m_level;
        unsigned int m_experience;

        Race* m_race;
        Gender m_gender;
        Class* m_class;
        Alignment* m_alignment;
        AttributesSet m_attributes_set;
        TraitsSet m_traits_set;
};

#endif // CHARACTER_H
