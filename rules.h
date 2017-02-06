#ifndef RULES_H
#define RULES_H

#include <QString>

namespace Rules {

const int DEFAULT_DICE = 5;

// additions to results
const int TRILING_ADDITION = 20;
const int STRAIGHT_FIRST_HAND = 66;
const int STRAIGHT_SECOND_HAND = 56;
const int STRAIGHT_THIRD_HAND = 46;
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
    None,
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

// colors
const QString FILLED_LABEL_COLOR = "QLabel {color: rgb(255, 255, 255); background-color: rgb(42, 104, 167) }";
const QString FREE_LABEL_COLOR = "QLabel { color: rgb(255, 255, 255); background-color: rgb(53, 134, 214) }";

}

#endif // RULES_H
