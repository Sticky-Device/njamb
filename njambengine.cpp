#include "njambengine.h"

NjambEngine::NjambEngine()
{

}

void NjambEngine::resetGame()
{
    numberOfRolls = 0;
    currentHand = {{6, 6, 6, 6, 6, 6}};
}

DiceHand NjambEngine::rollDice()
{
    ++numberOfRolls;
    currentHand = DiceHand();
    return currentHand;
}

DiceHand NjambEngine::getCurrentHand()
{
    return currentHand;
}

int NjambEngine::currentRoll()
{
    return numberOfRolls;
}

