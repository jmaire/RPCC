#ifndef ATTRIBUTESCORE_H
#define ATTRIBUTESCORE_H

#include "config.h"
#include "Class.h"
#include "Race.h"

class AttributeScore
{
    public:
        AttributeScore(std::string key);
        AttributeScore();

        virtual ~AttributeScore();

        int getActualScore();

        void setBonus(int b);
        void setBounds(Race* rc, Class* cl);

        bool isIncrementable();
        bool isDecrementable();

        void increasePoint(int p);

    protected:
        int m_score, m_bonus;
        std::pair<int,int> m_bounds;
        std::string m_key;

};

#endif // ATTRIBUTESCORE_H
