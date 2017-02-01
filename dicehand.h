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
    int getBestResult(Rules::YambField resultType, int currentRoll = 0);
    int getDice(int index);

    int& operator[](int index);

private:
    int getBestResultForNumber(int number);
    int getBestResultMax();
    int getBestResultMin();
    int getBestResultTriling();
    int getBestResultStraight(int currentRoll);
    int getBestResultFull();
    int getBestResultPoker();
    int getBestResultYamb();

    template<typename Operator1, typename Operator2>
    int getMaxDiceThatMeetsCriteria(int numberOf, Operator1 op1, Operator2 op2);
    int getMaxDiceThatWeHaveAtLeast(int numberOf);
    int getMaxDiceThatWeHaveExactly(int numberOf);
    int getMaxMinorDiceForFull(int majorFullDice);

private:
    void Init();

private:
    std::vector<int> dice;
};

#endif // DICEHAND_H
