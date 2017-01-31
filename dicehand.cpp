#include "dicehand.h"
#include "rules.h"

#include <random>
#include <numeric>
#include <algorithm>
#include <functional>

static int generateRandomDiceInteger()
{
    static std::mt19937 rng;
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

int DiceHand::getBestResult(Rules::YambField resultType)
{
    switch (resultType)
    {
    case Rules::YambField::Ones :
        return getBestResultForNumber(1);
    case Rules::YambField::Twos :
        return getBestResultForNumber(2);
    case Rules::YambField::Threes :
        return getBestResultForNumber(3);
    case Rules::YambField::Fours :
        return getBestResultForNumber(4);
    case Rules::YambField::Fives :
        return getBestResultForNumber(5);
    case Rules::YambField::Sixes :
        return getBestResultForNumber(6);
    case Rules::YambField::Max :
        return getBestResultMax();
    case Rules::YambField::Min :
        return getBestResultMin();
    case Rules::YambField::Triling :
        return getBestResultTriling();
    case Rules::YambField::Straight :
        return getBestResultStraight();
    case Rules::YambField::Full :
        return getBestResultFull();
    case Rules::YambField::Poker :
        return getBestResultPoker();
    case Rules::YambField::Yamb :
        return getBestResultYamb();
    default:
        break;
    }

    return 0;
}

// get dice by its index
int DiceHand::getDice(int index)
{
    if (index < 1 || index > 6)
        // mark error
        return 0;

    return dice[index - 1];
}

int &DiceHand::operator[](int index)
{
    return dice[index];
}

int DiceHand::getBestResultForNumber(int number)
{
    auto result = std::accumulate(dice.begin(), dice.end(), 0, [=](int currentResult, int element) {
       if (element != number)
           return currentResult;
       return currentResult + number;
    });

    auto maxRes = 5 * number;
    return result < maxRes ? result : maxRes;
}

int DiceHand::getBestResultMax()
{
    auto hand = dice;
    std::sort(begin(hand), end(hand));
    return std::accumulate(++begin(hand), end(hand), 0);
}

int DiceHand::getBestResultMin()
{
    auto hand = dice;
    std::sort(begin(hand), end(hand));
    return std::accumulate(begin(hand), --end(hand), 0);
}

int DiceHand::getBestResultTriling()
{
    auto maxDiceOf3 = getMaxDiceThatWeHaveAtLeast(3);
    if (maxDiceOf3 == 0)
        return 0;

    return 3 * maxDiceOf3 + Rules::TRILING_ADDITION;
}

int DiceHand::getBestResultStraight()
{
    return 0;
}

int DiceHand::getBestResultFull()
{
    auto maxDiceOf3 = getMaxDiceThatWeHaveAtLeast(3);
    auto maxDiceOf2 = getMaxDiceThatWeHaveExactly(2);

    if ((maxDiceOf2 == 0) || (maxDiceOf3 == 0))
        return 0;

    return 3 * maxDiceOf3 + 2 * maxDiceOf2 + Rules::FULL_ADDITION;
}

int DiceHand::getBestResultPoker()
{
    auto diceOf4 = getMaxDiceThatWeHaveAtLeast(4);
    if (diceOf4 == 0)
        return 0;

    return 4 * diceOf4 + Rules::POKER_ADDITION;
}

int DiceHand::getBestResultYamb()
{
    auto diceOf5 = getMaxDiceThatWeHaveAtLeast(5);
    if (diceOf5 == 0)
        return 0;

    return 5 * diceOf5 + Rules::YAMB_ADDITION;
}

int DiceHand::getMaxDiceThatWeHaveAtLeast(int numberOf)
{
    return getMaxDiceThatMeetsCriteria(numberOf, [](int a, int b) {return a >= b;});
}

int DiceHand::getMaxDiceThatWeHaveExactly(int numberOf)
{
    return getMaxDiceThatMeetsCriteria(numberOf, [](int a, int b) {return a == b;});
}

template<typename Operator>
int DiceHand::getMaxDiceThatMeetsCriteria(int numberOf, Operator op)
{
    std::vector<int> result;
    for (auto i : dice)
    {
        if (op(static_cast<int>(std::count(begin(dice), end(dice), i)), numberOf))
            result.push_back(i);
    }

    // check if this is needed at all
    if (result.empty())
        return 0;

    return *std::max_element(begin(result), end(result));
}

void DiceHand::Init()
{
    for (auto i = dice.size(); i < 6; ++i)
        dice.push_back(generateRandomDiceInteger());
}

