#ifndef CHARACTERISTICSCORE_H
#define CHARACTERISTICSCORE_H

#include "config.h"

class CharacteristicScore
{
    public:
        virtual ~CharacteristicScore();

        virtual int getActualScore();

    protected:
        int m_score;

        CharacteristicScore(int score);
        CharacteristicScore();

        virtual bool isScoreIncreasable(int op);
        bool increaseScore(int op);
};

#endif // CHARACTERISTICSCORE_H
