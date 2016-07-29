#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <vector>

#include "AttributeScore.h"
#include "Race.h"
#include "Class.h"

class AttributesSet
{
    public:
        AttributesSet(Race* rc, Class* cl);
        AttributesSet();

        virtual ~AttributesSet();

        bool isIncreasable(unsigned int ind);

        void addPoint(unsigned int ind);
        void removePoint(unsigned int ind);

        //void randomAssignment();

        std::string toString();

    protected:
        AttributeScore ma_attributes[ATTRIBUTES_SET_SIZE];
        int m_unassignedPoints;

};

#endif // ATTRIBUTES_SET_H
