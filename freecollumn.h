#ifndef FREECOLLUMN_H
#define FREECOLLUMN_H

#include "abstractcollumn.h"

class FreeCollumn : public AbstractCollumn
{
public:
    FreeCollumn(Ui::MainWindow* ui, NjambEngine& engine);

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

#endif // FREECOLLUMN_H
