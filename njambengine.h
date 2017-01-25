#ifndef NJAMBENGINE_H
#define NJAMBENGINE_H

#include "dicehand.h"

class NjambEngine
{
public:
    NjambEngine();

public:
    void resetGame();
    DiceHand rollDice();
    DiceHand getCurrentHand();
    int currentRoll();

private:
    DiceHand currentHand{{6, 6, 6, 6, 6, 6}}; // we start we all sixes (for now)
    int numberOfRolls = 0;
};

#endif // NJAMBENGINE_H
