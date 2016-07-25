#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <vector>

#include "config.h"
#include "AttributeScore.h"
#include "Race.h"
#include "Class.h"

class AttributesSet
{
    public:
        AttributesSet(Race* rc, Class* cl);
        AttributesSet(void);

        virtual ~AttributesSet(void);

        void randomAssignment(void);

        std::string toString(void);

    protected:
        int m_unassignedPoints;
        AttributeScore ma_attributes[ATTRIBUTES_SET_SIZE];
        std::pair<unsigned int,unsigned int> ma_attributesBounds[ATTRIBUTES_SET_SIZE];

};

#endif // ATTRIBUTES_SET_H
