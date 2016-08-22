#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "DataManager.h"
#include "AttributeSet.h"

namespace rpcc
{
    AttributeSet::AttributeSet(std::vector<std::string> a_attributeID)
    : CharacteristicSet(a_attributeID)
    , m_unassignedPoints(ATTRIBUTE_STARTING_UNASSIGNED_POINTS)
    {}

    AttributeSet::AttributeSet()
    : AttributeSet({"str","dex","con","int","wis","cha"}) //TODO
    {}

    AttributeSet::~AttributeSet()
    {}

    void AttributeSet::setAttributeBounds(Race* rc, Class* cl)
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

    void AttributeSet::setAttributeBonus(Race* rc)
    {
        for(std::map<std::string,AttributeScore>::iterator it=m_csMap.begin(); it!=m_csMap.end(); ++it)
        {
            m_csMap.at(it->first).setBonus(rc->getAttributeBonus(it->first));
        }
    }

    bool AttributeSet::isIncrementable(std::string key)
    {
        return isKeyUsed(key) && m_csMap.at(key).isIncrementable();
    }

    bool AttributeSet::isDecrementable(std::string key)
    {
        return isKeyUsed(key) && m_csMap.at(key).isDecrementable();
    }

    int AttributeSet::getNumberOfUnassignedPoints()
    {
        return m_unassignedPoints;
    }

    void AttributeSet::incrementByID(std::string key)
    {
        if(isIncrementable(key) && m_unassignedPoints>=1)
            if(m_csMap.at(key).incrementScore())
                m_unassignedPoints--;
    }

    void AttributeSet::decrementByID(std::string key)
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
    std::string AttributeSet::toString()
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

    std::string AttributeSet::toStringCreation()
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
}

