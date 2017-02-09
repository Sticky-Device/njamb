#ifndef NJAMBENGINE_H
#define NJAMBENGINE_H

#include "dicehand.h"
#include "rules.h"

#include <vector>

class NjambEngine
{
public:
    NjambEngine();

public:
    void nextRound();
    void resetGame();
    DiceHand rollDice(std::vector<int> savedDice = {});
    DiceHand getCurrentHand();
    int currentRoll();
    void CallFieldClicked();
    Rules::Mode getMode();

private:
    const DiceHand defaultHand = {{Rules::DEFAULT_DICE, Rules::DEFAULT_DICE, Rules::DEFAULT_DICE, Rules::DEFAULT_DICE, Rules::DEFAULT_DICE, Rules::DEFAULT_DICE}};
    DiceHand currentHand = defaultHand; // we start we all sixes (for now)
    int numberOfRolls = 0;
    Rules::Mode currentMode = Rules::Mode::Normal;
};

#endif // NJAMBENGINE_H
