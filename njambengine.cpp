#include "njambengine.h"

NjambEngine::NjambEngine()
{

}

void NjambEngine::resetGame()
{

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

