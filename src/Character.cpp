#include <algorithm>
#include <iostream>

#include "Character.h"

Character::Character()
: m_creationStep(CREATION_START)
, m_name(UNDEFINED_STRING)
, m_portraitPath(UNDEFINED_STRING)
, m_level(1)
, m_experience(0)
, m_race(nullptr)
, m_class(nullptr)
{}

Character::~Character()
{}

CharacterCreationStep Character::getCreationStep()
{
    return m_creationStep;
}

void Character::goToNextCreationStep()
{
    if(CREATION_DONE != m_creationStep)
        m_creationStep = (CharacterCreationStep)((int)(m_creationStep+1));
}

bool Character::isRaceValid()
{
    return nullptr != m_race;
}

bool Character::isGenderValid()
{
    return  Gender::FEMALE == m_gender || Gender::MALE == m_gender;
}

bool Character::isClassValid()
{
    if(nullptr == m_class || nullptr == m_race)
        return false;

    std::vector<std::string> availableClass = getAvailableClass();
    return std::find(availableClass.begin(),availableClass.end(),m_class->getID()) != availableClass.end();
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

std::vector<std::string> Character::getAvailableClass()
{
    if(m_race!=nullptr)
    {
        return m_race->getAvailableClass();
    }
    return std::vector<std::string>();
}

std::string Character::toString()
{
    std::string str = "Name: " + m_name
        + "\nRace: " + m_race->getName()
        + "\nGender: " + ((int)m_gender==0 ? "Female" : "Male")
        + "\nClass: " + m_class->getName()
        //+ "\nLevel: " + m_level + "(" + m_experience + ")"
        + "\nAttributes \n" + m_attributes_set.toString();

    return str;
}


