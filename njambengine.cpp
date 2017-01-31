#include "njambengine.h"
#include "rules.h"

#include <algorithm>

using namespace std;

NjambEngine::NjambEngine()
{

}

void NjambEngine::nextRound()
{
    numberOfRolls = 0;
}

void NjambEngine::resetGame()
{
    numberOfRolls = 0;
    currentHand = defaultHand;
}

DiceHand NjambEngine::rollDice(std::vector<int> savedDice)
{
    ++numberOfRolls;
    auto newHand = DiceHand();
    for(auto i = 0; i < 6; ++i)
    {
        // set only dice that are not selected
        if (find(begin(savedDice), end(savedDice), i) == end(savedDice))
            currentHand[i] = newHand[i];
    }

    return currentHand;
}

DiceHand NjambEngine::getCurrentHand()
{
    return currentHand;
}

int NjambEngine::currentRoll()
{
    return numberOfRolls % 4;
}
