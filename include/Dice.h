#ifndef DICE_H
#define DICE_H

#define DEFAULT_DICES_NUMBER 1
#define DEFAULT_DICE_FACES 6

class Dice
{
    public:
        Dice(unsigned int n, unsigned int f);
        Dice(void);

        virtual ~Dice(void);

        unsigned int roll(void);
        unsigned int immersiveRoll(void);

    protected:
        unsigned int m_number, m_faces;

};

#endif // DICE_H
