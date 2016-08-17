#ifndef ATTRIBUTESCORE_H
#define ATTRIBUTESCORE_H

#include "config.h"
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

        void increasePoint(int p);

        std::string toString();

    protected:
        std::string m_attributeID;
        int m_score, m_bonus;
        std::pair<int,int> m_bounds;

};

#endif // ATTRIBUTESCORE_H
