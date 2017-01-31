#ifndef RESULTS_H
#define RESULTS_H

#include "rules.h"

#include <map>

class Results
{
public:
    Results();
    void updateResult(Rules::Collumn, Rules::YambField, int result);
    int getResult(Rules::Collumn, Rules::CollumnGroup);
    int getResult(Rules::CollumnGroup group);
    int getFinalResult();

    void reset();

private:
    std::map<Rules::Collumn, std::map<Rules::YambField, int>> resultMap;
};

#endif // RESULTS_H
