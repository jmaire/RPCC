#include "Character.h"

Character::Character(void)
: m_level(1)
, m_experience(0)
, m_race(nullptr)
, m_class(nullptr)
, m_alignment(nullptr)
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

void Character::setAlignment(Alignment* al)
{
    m_alignment = al;
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

std::vector<Alignment*> Character::getAvailableAlignment(void)
{
    if(m_class!=nullptr)
    {
        return m_class->getAvailableAlignment();
    }
    std::vector<Alignment*> noAlignment;
    noAlignment.clear();
    return noAlignment;
}

