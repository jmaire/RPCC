#include "CharacteristicScore.h"

namespace rpcc
{
    CharacteristicScore::CharacteristicScore(int score)
    : m_score (score)
    {}

    CharacteristicScore::CharacteristicScore()
    : CharacteristicScore(0)
    {}

    CharacteristicScore::~CharacteristicScore()
    {}

    int CharacteristicScore::getActualScore()
    {
        return m_score;
    }

    bool CharacteristicScore::isScoreIncreasable(int op)
    {
        return true;
    }

    bool CharacteristicScore::increaseScore(int op)
    {
        m_score += op;
        return true;
    }
}
