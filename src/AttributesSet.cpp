#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "AttributesSet.h"

AttributesSet::AttributesSet(Race* rc, Class* cl)
: m_unassignedPoints(ATTRIBUTE_STARTING_UNASSIGNED_POINTS)
{
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        //ma_attributes[i] = AttributeScore();
        int lb = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        int hb = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
        if(rc!=nullptr && cl!=nullptr)
        {
            std::pair<int,int> rcBounds = rc->getAttributeBounds(i);
            std::pair<int,int> clBounds = cl->getAttributeBounds(i);
            lb = MY_MAX(rcBounds.first,clBounds.first);
            hb = MY_MIN(rcBounds.second,clBounds.second);
        }

        ma_attributes[i].setBounds(lb,hb);
    }
}


AttributesSet::AttributesSet()
: AttributesSet(nullptr, nullptr)
{}

/*virtual*/ AttributesSet::~AttributesSet()
{}

bool AttributesSet::isIncreasable(unsigned int ind)
{
    return ma_attributes[ind].isIncreasable();
}

void AttributesSet::addPoint(unsigned int ind)
{
    AttributeScore as = ma_attributes[ind];
    m_unassignedPoints -= abs(as.getPointCost());
    as.increasePoint(1);
}

void AttributesSet::removePoint(unsigned int ind)
{
    AttributeScore as = ma_attributes[ind];
    m_unassignedPoints += abs(as.getPointCost());
    as.increasePoint(-1);
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
    }
    sprintf(buff,"%d",m_unassignedPoints);
    return str + "  >Unassigned: " + buff;
}


