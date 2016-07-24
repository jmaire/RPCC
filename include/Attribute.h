#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

#define ATTRIBUTE_SCORE_MIN 3
#define ATTRIBUTE_SCORE_MAX 18

class Attribute
{
    public:
        Attribute(unsigned int s);
        Attribute();

        virtual ~Attribute();

        unsigned int getScore(void);
        void setScore(unsigned int s);

        void incrementScore(void);
        void decrementScore(void);

    protected:
        unsigned int m_score;
};

#endif // ATTRIBUTE_H
