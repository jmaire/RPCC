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
        m_csMap[attributes[i]] = AttributeScore(attributes[i]);
}

AttributesSet::AttributesSet()
: AttributesSet({"str","dex","con","int","wis","cha"}) //TODO
{}

AttributesSet::~AttributesSet()
{}

void AttributesSet::setAttributeBounds(Race* rc, Class* cl)
{
    for(std::map<std::string,AttributeScore>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
    {
        int lowerBoundary = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        if(cl->haveAttributeLowBoundary(it->first))
            lowerBoundary = cl->getAttributeLowBoundary(it->first);
        else if(rc->haveAttributeLowerBoundary(it->first))
            lowerBoundary = rc->getAttributeLowerBoundary(it->first);

        int higherBoundary = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
        if(rc->haveAttributeHigherBoundary(it->first))
            higherBoundary = rc->getAttributeHigherBoundary(it->first);

        it->second.setBounds(lowerBoundary,higherBoundary);
    }
}

void AttributesSet::setAttributeBonus(Race* rc)
{
    for(std::map<std::string,AttributeScore>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
    {
        m_csMap.at(it->first).setBonus(rc->getAttributeBonus(it->first));
    }
}

bool AttributesSet::isIncrementable(std::string key)
{
    return isKeyUsed(key) && m_csMap.at(key).isIncrementable();
}

bool AttributesSet::isDecrementable(std::string key)
{
    return isKeyUsed(key) && m_csMap.at(key).isDecrementable();
}

int AttributesSet::getNumberOfUnassignedPoints()
{
    return m_unassignedPoints;
}

void AttributesSet::incrementByID(std::string key)
{
    if(isIncrementable(key) && m_unassignedPoints>=1)
        if(m_csMap.at(key).incrementScore())
            m_unassignedPoints--;
}

void AttributesSet::decrementByID(std::string key)
{
    if(isDecrementable(key))
        if(m_csMap.at(key).decrementScore())
            m_unassignedPoints++;
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
    for(std::map<std::string,AttributeScore>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
    {
        str += it->second.toString() + "\n";
    }

    char buff[16];
    sprintf(buff,"\t|> Unassigned: %d",m_unassignedPoints);
    str += buff;

    return str;
}

std::string AttributesSet::toStringCreation()
{
    std::string str = "";
    for(std::map<std::string,AttributeScore>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
    {
        if(isDecrementable(it->first))
            str += "[-/";
        else
            str += "[ /";

        if(isIncrementable(it->first))
            str += "+]";
        else
            str += " ]";

        str += it->second.toStringCreation() + "\n";
    }

    char buff[16];
    sprintf(buff,"\t|> Unassigned: %d",m_unassignedPoints);
    str += buff;

    return str;
}


