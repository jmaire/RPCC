#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <map>
#include <vector>

#include "AttributeScore.h"
#include "Race.h"
#include "Class.h"

class AttributesSet
{
    public:
        AttributesSet(std::vector<std::string> attributes);
        AttributesSet();

        virtual ~AttributesSet();

        void setAttributeBounds(Race* rc, Class* cl);
        void setAttributeBonus(Race* rc);

        bool isIncrementable(std::string key);
        bool isDecrementable(std::string key);

        void incrementPoint(std::string key);
        void decrementPoint(std::string key);

        //void randomAssignment();

        std::string toString();

    protected:
        std::map<std::string,AttributeScore*> m_asMap;
        int m_unassignedPoints;

};

#endif // ATTRIBUTES_SET_H
