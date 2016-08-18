#ifndef ATTRIBUTESCORE_H
#define ATTRIBUTESCORE_H

#include "Class.h"
#include "Race.h"

class AttributeScore
{
    public:
        AttributeScore(std::string attributeID);
        AttributeScore();

        virtual ~AttributeScore();

        int getActualScore();

        void setBonus(int b);
        void setBounds(int lowerBoundary, int higherBoundary);

        bool isIncrementable();
        bool isDecrementable();

        bool increment();
        bool decrement();

        std::string toString();
        std::string toStringCreation();

    protected:
        std::string m_attributeID;
        int m_score, m_bonus;
        std::pair<int,int> m_bounds;

};

#endif // ATTRIBUTESCORE_H
