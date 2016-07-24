#ifndef TRAIT_H
#define TRAIT_H


class Trait
{
    public:
        Trait(int sc);
        Trait(void);

        virtual ~Trait(void);

        unsigned int getScore(void);
        void setScore(unsigned int sc);

    protected:
        int m_score;
};

#endif // TRAIT_H
