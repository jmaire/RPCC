#include <algorithm>
#include <iostream>

#include "Character.h"

Character::Character(void)
: m_creationStep(START)
, m_name(UNDEFINED_STRING)
, m_portraitPath(UNDEFINED_STRING)
, m_level(1)
, m_experience(0)
, m_race(nullptr)
, m_class(nullptr)
{}

/*virtual*/ Character::~Character(void)
{}

CharacterCreationStep Character::getCreationStep(void)
{
    return m_creationStep;
}

void Character::goToNextCreationStep(void)
{
    if(DONE != m_creationStep)
        m_creationStep = (CharacterCreationStep)((int)(m_creationStep+1));
}

bool Character::isRaceValid(void)
{
    return nullptr != m_race;
}

bool Character::isGenderValid(void)
{
    return  Gender::FEMALE == m_gender || Gender::MALE == m_gender;
}

bool Character::isClassValid(void)
{
    if(nullptr != m_class && nullptr != m_race)
    {
        std::vector<Class*>* availableClass = getAvailableClass();
        return std::find(availableClass->begin(),availableClass->end(),m_class) != availableClass->end();
    }
    return false;
}

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

std::vector<Class*>* Character::getAvailableClass(void)
{
    if(m_race!=nullptr)
    {
        return m_race->getAvailableClass();
    }
    return nullptr;
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


