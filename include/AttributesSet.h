#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <vector>

#include "AttributeScore.h"
#include "CharacteristicSet.h"
#include "Class.h"
#include "Race.h"

class AttributesSet : public CharacteristicSet<AttributeScore>
{
    public:
        AttributesSet(std::vector<std::string> a_attributeID);
        AttributesSet();

        virtual ~AttributesSet();

        void setAttributeBounds(Race* rc, Class* cl);
        void setAttributeBonus(Race* rc);

        bool isIncrementable(std::string key);
        bool isDecrementable(std::string key);
        int getNumberOfUnassignedPoints();

        void incrementByID(std::string key);
        void decrementByID(std::string key);

        //void randomAssignment();

        std::string toString();
        std::string toStringCreation();

    protected:
        int m_unassignedPoints;

};

#endif // ATTRIBUTES_SET_H
