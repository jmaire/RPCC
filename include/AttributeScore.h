#ifndef ATTRIBUTESCORE_H
#define ATTRIBUTESCORE_H

#include "config.h"

class AttributeScore
{
    public:
        AttributeScore();

        virtual ~AttributeScore();

        int getActualScore();

        int getPointsCost();
        int getNextPointCost();
        int getPreviousPointCost();

        void setBonus(int b);
        void setBounds(int min, int max);

        bool isIncrementable();
        bool isDecrementable();

        void increasePoint(int p);

    protected:
        int m_score, m_bonus;
        std::pair<int,int> m_bounds;

};

#endif // ATTRIBUTESCORE_H
