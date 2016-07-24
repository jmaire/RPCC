#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Dice.h"

Dice::Dice(unsigned int n, unsigned int f)
: m_number(n)
, m_faces(f)
{
    srand(time(nullptr));
}

Dice::Dice()
: Dice(DEFAULT_DICES_NUMBER, DEFAULT_DICE_FACES)
{}

/*virtual*/ Dice::~Dice()
{}

unsigned int Dice::roll(void)
{
    return (rand() % ((m_faces-1) * m_number+1)) + m_number;
}

unsigned int Dice::immersiveRoll(void)
{
    unsigned int score = 0;
    for(unsigned int i=0; i<m_number; i++)
    {
        score += rand() % m_faces + 1;
    }
    return score;
}
