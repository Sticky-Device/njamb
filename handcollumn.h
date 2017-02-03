#ifndef HANDCOLLUMN_H
#define HANDCOLLUMN_H

#include "abstractcollumn.h"

class HandCollumn : public AbstractCollumn
{
public:
    HandCollumn(Ui::MainWindow* ui, NjambEngine& engine);

public:
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
};

#endif // HANDCOLLUMN_H
