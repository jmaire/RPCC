#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "DataManager.h"
#include "AttributesSet.h"


AttributesSet::AttributesSet(std::vector<std::string> attributes)
: m_unassignedPoints(ATTRIBUTE_STARTING_UNASSIGNED_POINTS)
{
    for(unsigned int i=0; i<attributes.size(); i++)
    {
        AttributeScore* as = new AttributeScore(attributes[i]);
        m_asMap[attributes[i]] = as;
    }
}

AttributesSet::AttributesSet()
: AttributesSet({"str","dex","con","int","wis","cha"}) //TODO
{}

AttributesSet::~AttributesSet()
{}

void AttributesSet::setAttributeBounds(Race* rc, Class* cl)
{
    for(std::map<std::string,AttributeScore*>::iterator it=m_asMap.begin(); it!=m_asMap.end(); ++it)
    {
        int lowerBoundary = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        if(cl->haveAttributeLowBoundary(it->first))
            lowerBoundary = cl->getAttributeLowBoundary(it->first);
        else if(rc->haveAttributeLowerBoundary(it->first))
            lowerBoundary = rc->getAttributeLowerBoundary(it->first);

        int higherBoundary = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
        if(rc->haveAttributeHigherBoundary(it->first))
            higherBoundary = rc->getAttributeHigherBoundary(it->first);

        it->second->setBounds(lowerBoundary,higherBoundary);
    }
}

void AttributesSet::setAttributeBonus(Race* rc)
{
    for(std::map<std::string,AttributeScore*>::iterator it=m_asMap.begin(); it!=m_asMap.end(); ++it)
    {
        m_asMap.at(it->first)->setBonus(rc->getAttributeBonus(it->first));
    }
}

bool AttributesSet::isKeyUsed(std::string key)
{
    return m_asMap.find(key) != m_asMap.end();
}

bool AttributesSet::isIncrementable(std::string key)
{
    return isKeyUsed(key) && m_asMap.at(key)->isIncrementable();
}

bool AttributesSet::isDecrementable(std::string key)
{
    return isKeyUsed(key) && m_asMap.at(key)->isDecrementable();
}

void AttributesSet::incrementPoint(std::string key)
{
    if(isKeyUsed(key))
    {
        m_asMap.at(key)->increasePoint(1);
        m_unassignedPoints--;
    }
}

void AttributesSet::decrementPoint(std::string key)
{
    if(isKeyUsed(key))
    {
        m_asMap.at(key)->increasePoint(-1);
        m_unassignedPoints++;
    }
}

/*
void AttributesSet::randomAssignment()
{
    srand(time(nullptr));

    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        unsigned int points = ma_attributesBounds[i].first;
        ma_attributes[i].m_score = points;
        m_unassignedPoints -= points;
    }

    //TODO negative?

    while(m_unassignedPoints>0)
    {
        unsigned int ind = rand() % ATTRIBUTES_SET_SIZE;
        if(ma_attributes[ind].m_score < ma_attributesBounds[ind].second)
        {
            ma_attributes[ind].m_score++;
            m_unassignedPoints--;
        }
    }
}
*/
std::string AttributesSet::toString()
{
    std::string str = "";
    for(std::map<std::string,AttributeScore*>::iterator it=m_asMap.begin(); it!=m_asMap.end(); ++it)
    {
        str += it->second->toString() + "\n";
    }

    char buff[16];
    sprintf(buff,"\t|> Unassigned: %d",m_unassignedPoints);
    str += buff;

    return str;
}

std::string AttributesSet::toStringSettings()
{
    std::string str = "";
    for(std::map<std::string,AttributeScore*>::iterator it=m_asMap.begin(); it!=m_asMap.end(); ++it)
    {
        if(isDecrementable(it->first))
            str += "[-]";
        else
            str += "   ";

        if(isIncrementable(it->first))
            str += "[+]";
        else
            str += "   ";

        str += " " + it->second->toString() + "\n";
    }

    char buff[16];
    sprintf(buff,"\t|> Unassigned: %d",m_unassignedPoints);
    str += buff;

    return str;
}


