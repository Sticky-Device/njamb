#include "dicehand.h"
#include <random>

static int generateRandomDiceInteger()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    return dist6(rng);
}

DiceHand::DiceHand()
{
    Init();
}

DiceHand::DiceHand(std::vector<int> savedDice)
{
    if (savedDice.size() > 6)
        // mark some kind of an error
        return;

    dice.swap(savedDice); // take what's in
    Init(); // init remaining
}

int DiceHand::getBestResult(DiceHandResult resultType)
{
    switch (resultType)
    {
    case DiceHandResult::Ones :
        return getBestResultForNumber(1);
    case DiceHandResult::Twos :
        return getBestResultForNumber(2);
    case DiceHandResult::Threes :
        return getBestResultForNumber(3);
    case DiceHandResult::Fours :
        return getBestResultForNumber(4);
    case DiceHandResult::Fives :
        return getBestResultForNumber(5);
    case DiceHandResult::Sixes :
        return getBestResultForNumber(6);
    default:
        break;
    }

    return 0;
}

int DiceHand::getDice(int index)
{
    if (index < 1 || index > 6)
        // mark error
        return 0;

    return dice[index - 1];
}

int DiceHand::getBestResultForNumber(int number)
{
    int result = 0;
    for (auto val : dice)
        if (val == number)
            result += number;

    return result;
}

void DiceHand::Init()
{
    for (int i = dice.size(); i < 6; ++i)
        dice.push_back(generateRandomDiceInteger());
}

