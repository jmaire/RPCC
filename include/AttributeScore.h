#ifndef ATTRIBUTESCORE_H
#define ATTRIBUTESCORE_H

#include <string>

#define ATTRIBUTE_SCORE_MIN 3
#define ATTRIBUTE_SCORE_MAX 18

class AttributeScore
{
    public:
        AttributeScore(unsigned int sc);
        AttributeScore(void);

        virtual ~AttributeScore(void);

        unsigned int getScore(void);
        void setScore(unsigned int sc);

        void incrementScore(void);
        void decrementScore(void);

    protected:
        unsigned int m_score;
};

#endif // ATTRIBUTESCORE_H
