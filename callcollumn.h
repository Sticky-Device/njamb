#ifndef CALLCOLLUMN_H
#define CALLCOLLUMN_H

#include "abstractcollumn.h"

class CallCollumn : public AbstractCollumn
{
public:
    CallCollumn(Ui::MainWindow* ui, NjambEngine& engine, Results &results);

public:
    std::vector<Rules::YambField> getPlayableFields() override;

private:
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

#endif // CALLCOLLUMN_H
