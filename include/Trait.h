#ifndef TRAIT_H
#define TRAIT_H


class Trait
{
    public:
        Trait(int sc);
        Trait(void);

        virtual ~Trait(void);

        int getScore(void);
        void setScore(int sc);
        void increaseScore(int i);

    protected:
        int m_score;
};

#endif // TRAIT_H
