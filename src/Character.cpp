#include <iostream>

#include "Character.h"

Character::Character(void)
: m_portraitPath(nullptr)
, m_level(1)
, m_experience(0)
, m_race(nullptr)
, m_class(nullptr)
{}

/*virtual*/ Character::~Character(void)
{}

void Character::setName(std::string nm)
{
    m_name = nm;
}

void Character::setRace(Race* rc)
{
    m_race = rc;
}

void Character::setGender(Gender gd)
{
    m_gender = gd;
}

void Character::setClass(Class* cl)
{
    m_class = cl;
}

std::vector<Class*> Character::getAvailableClass(void)
{
    if(m_race!=nullptr)
    {
        return m_race->getAvailableClass();
    }
    std::vector<Class*> noClass;
    noClass.clear();
    return noClass;
}

std::string Character::toString(void)
{
    std::string str = "Name: " + m_name
        + "\nRace: " + *m_race->getName()
        + "\nGender: " + ((int)m_gender==0 ? "Female" : "Male")
        + "\nClass: " + *m_class->getName()
        //+ "\nLevel: " + m_level + "(" + m_experience + ")"
        + "\nAttributes \n" + m_attributes_set.toString();

    return str;
}


