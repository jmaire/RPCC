#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "AttributesSet.h"

AttributesSet::AttributesSet(Race* rc, Class* cl)
: m_unassignedPoints(0)
{
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        unsigned int lb = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        unsigned int hb = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
        if(rc!=nullptr && cl!=nullptr)
        {
            std::pair<unsigned int,unsigned int> rcBounds = rc->getAttributeBounds(i);
            std::pair<unsigned int,unsigned int> clBounds = cl->getAttributeBounds(i);
            lb = MY_MAX(rcBounds.first,clBounds.first);
            hb = MY_MIN(rcBounds.second,clBounds.second);
        }

        ma_attributesBounds[i].first = lb;
        ma_attributesBounds[i].second = hb;
    }
}


AttributesSet::AttributesSet(void)
: AttributesSet(nullptr, nullptr)
{
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        ma_attributes[i] = Attribute();
        ma_attributesBounds[i].first = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        ma_attributesBounds[i].second = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
    }
}

/*virtual*/ AttributesSet::~AttributesSet(void)
{}

void AttributesSet::randomAssignment(void)
{
    srand(time(nullptr));

    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        unsigned int points = ma_attributesBounds[i].first;
        ma_attributes[i].setScore(points);
        m_unassignedPoints -= points;
    }

    //TODO negative?

    while(m_unassignedPoints>0)
    {
        unsigned int ind = rand() % ATTRIBUTES_SET_SIZE;
        if(ma_attributes[ind].getScore() < ma_attributesBounds[ind].second)
        {
            ma_attributes[ind].incrementScore();
            m_unassignedPoints--;
        }
    }
}

void AttributesSet::display(void)
{
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        std::cout << "[" << ATTRIBUTES_SET_ATTRIBUTE_NAME[i] << "] : " << ma_attributes[i].getScore() << " [" << ma_attributesBounds[i].first << ":" << ma_attributesBounds[i].second << "]\n";
    }
    std::cout << "---\n[Unassigned] : " << m_unassignedPoints << "\n";

}

