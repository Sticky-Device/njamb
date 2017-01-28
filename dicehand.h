#ifndef DICEHAND_H
#define DICEHAND_H

#include <vector>

enum class DiceHandResult
{
    Ones,
    Twos,
    Threes,
    Fours,
    Fives,
    Sixes,
    Max,
    Min,
    Triling,
    Kenta,
    Full,
    Poker,
    Yamb
};

class DiceHand
{
public:
    DiceHand();
    DiceHand(std::vector<int> savedDice);

public:
    int getBestResult(DiceHandResult resultType);
    int getDice(int index);

    int& operator[](int index);

private:
    int getBestResultForNumber(int number);

private:
    void Init();

private:
    std::vector<int> dice;
};

#endif // DICEHAND_H
