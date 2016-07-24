#ifndef ALIGNMENT_H
#define ALIGNMENT_H

enum class EthicalAlignment
{
	LAWFUL = 0,
	NEUTRAL = 1,
    CHAOTIC = 2,
	ETHICAL_ALIGNMENT_COUNT
};

enum class MoralAlignment
{
	GOOD = 0,
	NEUTRAL = 1,
    EVIL = 2,
	MORAL_ALIGNMENT_COUNT
};

class Alignment
{
    public:
        Alignment();
        Alignment(EthicalAlignment eA, MoralAlignment mA);
        virtual ~Alignment();

    protected:
        EthicalAlignment m_ethicalAlignment;
        MoralAlignment m_moralAlignment;
};

#endif // ALIGNMENT_H
