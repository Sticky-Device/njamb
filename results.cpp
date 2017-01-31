#include "results.h"
#include "rules.h"

static std::map<Rules::Collumn, std::map<Rules::YambField, int>> defaultMap = { {Rules::Collumn::Free,
                                                                          { {Rules::YambField::Ones, 0},
                                                                            {Rules::YambField::Twos, 0},
                                                                            {Rules::YambField::Threes, 0},
                                                                            {Rules::YambField::Fours, 0},
                                                                            {Rules::YambField::Fives, 0},
                                                                            {Rules::YambField::Sixes, 0},
                                                                            {Rules::YambField::Max, 0},
                                                                            {Rules::YambField::Min, 0},
                                                                            {Rules::YambField::Triling, 0},
                                                                            {Rules::YambField::Straight, 0},
                                                                            {Rules::YambField::Full, 0},
                                                                            {Rules::YambField::Poker, 0},
                                                                            {Rules::YambField::Yamb, 0}
                                                                          }
                                                                         }
                                                                       };

Results::Results()
{
    reset();
}

void Results::updateResult(Rules::Collumn collumn, Rules::YambField field, int result)
{
    resultMap[collumn][field] = result;
}

int Results::getResult(Rules::Collumn collumn, Rules::CollumnGroup group)
{
    switch (collumn) {
    case Rules::Collumn::Free:
        switch (group) {
        case Rules::CollumnGroup::Numbers:
            return resultMap[Rules::Collumn::Free][Rules::YambField::Ones] +
                   resultMap[Rules::Collumn::Free][Rules::YambField::Twos] +
                   resultMap[Rules::Collumn::Free][Rules::YambField::Threes] +
                   resultMap[Rules::Collumn::Free][Rules::YambField::Fours] +
                   resultMap[Rules::Collumn::Free][Rules::YambField::Fives] +
                   resultMap[Rules::Collumn::Free][Rules::YambField::Sixes];

        case Rules::CollumnGroup::MinMax:
            return (resultMap[Rules::Collumn::Free][Rules::YambField::Max] -
                    resultMap[Rules::Collumn::Free][Rules::YambField::Min]) *
                    resultMap[Rules::Collumn::Free][Rules::YambField::Ones];
        case Rules::CollumnGroup::Major :
            return resultMap[Rules::Collumn::Free][Rules::YambField::Triling] +
                    resultMap[Rules::Collumn::Free][Rules::YambField::Straight] +
                    resultMap[Rules::Collumn::Free][Rules::YambField::Full] +
                    resultMap[Rules::Collumn::Free][Rules::YambField::Poker] +
                    resultMap[Rules::Collumn::Free][Rules::YambField::Yamb];
        default:
            break;
        }
        break;
    default:
        break;
    }

    return 0;
}

int Results::getResult(Rules::CollumnGroup group)
{
    return getResult(Rules::Collumn::Down, group) +
           getResult(Rules::Collumn::Free, group) +
           getResult(Rules::Collumn::Up, group) +
           getResult(Rules::Collumn::UpDown, group) +
           getResult(Rules::Collumn::Hand, group) +
           getResult(Rules::Collumn::Call, group);
}

int Results::getFinalResult()
{
    return getResult(Rules::CollumnGroup::Numbers) + getResult(Rules::CollumnGroup::MinMax) + getResult(Rules::CollumnGroup::Major);
}

void Results::reset()
{
    resultMap = defaultMap;
}


