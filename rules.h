#ifndef RULES_H
#define RULES_H

namespace Rules {

const int DEFAULT_DICE = 5;

// additions to results
const int TRILING_ADDITION = 20;
const int STRAIGHT_ADDITION = 0;
const int FULL_ADDITION = 30;
const int POKER_ADDITION = 40;
const int YAMB_ADDITION = 50;

enum class Collumn {
    Down,
    Free,
    Up,
    UpDown,
    Hand,
    Call
};

enum class YambField
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
    Straight,
    Full,
    Poker,
    Yamb
};

enum class CollumnGroup {
    Numbers,
    MinMax,
    Major
};

}

#endif // RULES_H
