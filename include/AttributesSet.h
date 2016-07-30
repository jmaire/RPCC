#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <vector>

#include "AttributeScore.h"
#include "Race.h"
#include "Class.h"

class AttributesSet
{
    public:
        AttributesSet();

        virtual ~AttributesSet();

        void setAttributeBounds(Race* rc, Class* cl);

        bool isIncrementable(unsigned int ind);
        bool isDecrementable(unsigned int ind);

        void incrementPoint(unsigned int ind);
        void decrementPoint(unsigned int ind);

        //void randomAssignment();

        std::string toString();

    protected:
        AttributeScore ma_attributes[ATTRIBUTES_SET_SIZE];
        int m_unassignedPoints;

};

#endif // ATTRIBUTES_SET_H
