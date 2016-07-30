#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "AttributesSet.h"

AttributesSet::AttributesSet()
: m_unassignedPoints(ATTRIBUTE_STARTING_UNASSIGNED_POINTS)
{}

/*virtual*/ AttributesSet::~AttributesSet()
{}

void AttributesSet::setAttributeBounds(Race* rc, Class* cl)
{
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        std::pair<int,int> rcBounds = rc->getAttributeBounds(i);
        std::pair<int,int> clBounds = cl->getAttributeBounds(i);
        ma_attributes[i].setBounds(MY_MAX(rcBounds.first,clBounds.first),
                                   MY_MIN(rcBounds.second,clBounds.second));
    }
}

bool AttributesSet::isIncrementable(unsigned int ind)
{
    return ma_attributes[ind].isIncrementable();
}

bool AttributesSet::isDecrementable(unsigned int ind)
{
    return ma_attributes[ind].isDecrementable();
}

void AttributesSet::incrementPoint(unsigned int ind)
{
    m_unassignedPoints -= ma_attributes[ind].getNextPointCost();
    ma_attributes[ind].increasePoint(1);
}

void AttributesSet::decrementPoint(unsigned int ind)
{
    m_unassignedPoints += ma_attributes[ind].getPreviousPointCost();
    ma_attributes[ind].increasePoint(-1);
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
    char buff[16];

    std::string str = "";
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        sprintf(buff,"%d",ma_attributes[i].getActualScore());
        str += "  " + ATTRIBUTES_SET_ATTRIBUTE_NAME[i] + ": " + buff + "\n";
        sprintf(buff,"%d",ma_attributes[i].getActualScore());
    }
    sprintf(buff,"%d",m_unassignedPoints);
    return str + "  >Unassigned: " + buff;
}


