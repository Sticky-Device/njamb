#include "dicehand.h"
#include "rules.h"

#include <set>
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

int DiceHand::getBestResult(Rules::YambField resultType, int currentRoll)
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
        return getBestResultStraight(currentRoll);
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

int DiceHand::getBestResultStraight(int currentRoll)
{
    if (currentRoll < 1 || currentRoll > 3)
        return 0; // mark error

    std::set<int> diceSet(begin(dice), end(dice));
    if (diceSet.size() < 5)
        return 0;

    switch (currentRoll) {
    case 1:
        return Rules::STRAIGHT_FIRST_HAND;
    case 2:
        return Rules::STRAIGHT_SECOND_HAND;
    case 3 :
        return Rules::STRAIGHT_THIRD_HAND;
    default:
        break;
    }

    return 0;
}

int DiceHand::getBestResultFull()
{
    auto majorDice = getMaxDiceThatWeHaveAtLeast(3);
    auto minorDice = getMaxMinorDiceForFull(majorDice);

    if ((majorDice == 0) || (minorDice == 0))
        return 0;

    return 3 * majorDice + 2 * minorDice + Rules::FULL_ADDITION;
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
    return getMaxDiceThatMeetsCriteria(numberOf, [](int a, int b) {return a >= b;}, [](int){return true;});
}

int DiceHand::getMaxDiceThatWeHaveExactly(int numberOf)
{
    return getMaxDiceThatMeetsCriteria(numberOf, [](int a, int b) {return a == b;}, [](int){return true;});
}

int DiceHand::getMaxMinorDiceForFull(int majorFullDice)
{
    return getMaxDiceThatMeetsCriteria(2, [](int a, int b) {return a >= b;}, [=](int dice){ return dice != majorFullDice; });
}

template<typename Operator1, typename Operator2>
int DiceHand::getMaxDiceThatMeetsCriteria(int numberOf, Operator1 op1, Operator2 op2)
{
    std::vector<int> result;
    for (auto i : dice)
    {
        if (op1(static_cast<int>(std::count(begin(dice), end(dice), i)), numberOf) && op2(i))
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

