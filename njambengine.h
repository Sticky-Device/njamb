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

};

#endif // NJAMBENGINE_H
