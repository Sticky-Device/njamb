#ifndef UPDOWNCOLLUMN_H
#define UPDOWNCOLLUMN_H

#include "abstractcollumn.h"

class UpDownCollumn : public AbstractCollumn
{
public:
    UpDownCollumn(Ui::MainWindow* ui, NjambEngine& engine, Results &results);

public:
    void reset() override;
    std::vector<Rules::YambField> getPlayableFields() override;

public:
    ClickableLabel* getUIElementOnes() override;
    ClickableLabel* getUIElementTwos() override;
    ClickableLabel* getUIElementThrees() override;
    ClickableLabel* getUIElementFours() override;
    ClickableLabel* getUIElementFives() override;
    ClickableLabel* getUIElementSixes() override;
    ClickableLabel* getUIElementMax() override;
    ClickableLabel* getUIElementMin() override;
    ClickableLabel* getUIElementTriling() override;
    ClickableLabel* getUIElementStraight() override;
    ClickableLabel* getUIElementFull() override;
    ClickableLabel* getUIElementPoker() override;
    ClickableLabel* getUIElementYamb() override;

private:
    Rules::Collumn getCollumn() override;
};

#endif // UPDOWNCOLLUMN_H
