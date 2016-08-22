#ifndef ATTRIBUTES_SET_H
#define ATTRIBUTES_SET_H

#include <vector>

#include "AttributeScore.h"
#include "CharacteristicSet.h"
#include "Class.h"
#include "Race.h"

namespace rpcc
{
    class AttributeSet : public CharacteristicSet<AttributeScore>
    {
        public:
            AttributeSet(std::vector<std::string> a_attributeID);
            AttributeSet();

            virtual ~AttributeSet();

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
}

#endif // ATTRIBUTES_SET_H
