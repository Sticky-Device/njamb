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
    switch (group) {
    case Rules::CollumnGroup::Numbers:
        return resultMap[collumn][Rules::YambField::Ones] +
               resultMap[collumn][Rules::YambField::Twos] +
               resultMap[collumn][Rules::YambField::Threes] +
               resultMap[collumn][Rules::YambField::Fours] +
               resultMap[collumn][Rules::YambField::Fives] +
               resultMap[collumn][Rules::YambField::Sixes];

    case Rules::CollumnGroup::MinMax:
    {
        auto result = (resultMap[collumn][Rules::YambField::Max] -
                        resultMap[collumn][Rules::YambField::Min]) *
                        resultMap[collumn][Rules::YambField::Ones];

        if (result < 0)
            return 0;

        return result;
    }
    case Rules::CollumnGroup::Major :
        return resultMap[collumn][Rules::YambField::Triling] +
                resultMap[collumn][Rules::YambField::Straight] +
                resultMap[collumn][Rules::YambField::Full] +
                resultMap[collumn][Rules::YambField::Poker] +
                resultMap[collumn][Rules::YambField::Yamb];
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


