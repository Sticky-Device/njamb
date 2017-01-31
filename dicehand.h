#ifndef DICEHAND_H
#define DICEHAND_H

#include "rules.h"

#include <vector>

class DiceHand
{
public:
    DiceHand();
    DiceHand(std::vector<int> savedDice);

public:
    int getBestResult(Rules::YambField resultType);
    int getDice(int index);

    int& operator[](int index);

private:
    int getBestResultForNumber(int number);
    int getBestResultMax();
    int getBestResultMin();
    int getBestResultTriling();
    int getBestResultStraight();
    int getBestResultFull();
    int getBestResultPoker();
    int getBestResultYamb();

    template<typename Operator>
    int getMaxDiceThatMeetsCriteria(int numberOf, Operator op);
    int getMaxDiceThatWeHaveAtLeast(int numberOf);
    int getMaxDiceThatWeHaveExactly(int numberOf);

private:
    void Init();

private:
    std::vector<int> dice;
};

#endif // DICEHAND_H
