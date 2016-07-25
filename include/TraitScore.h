#ifndef TRAITSCORE_H
#define TRAITSCORE_H

#include "Trait.h"

class TraitScore
{
    public:
        TraitScore(Trait* tr, int sc);
        TraitScore(Trait* tr);
        TraitScore(void);

        virtual ~TraitScore(void);

        int getScore(void);
        void setScore(int sc);
        void increaseScore(int i);

        std::vector<Ability*> getKnownAbilities(void);

    protected:
        Trait* m_trait;
        int m_score;

};

#endif // TRAITSCORE_H
