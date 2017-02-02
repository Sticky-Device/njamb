#ifndef UPCOLLUMN_H
#define UPCOLLUMN_H

#include "abstractcollumn.h"

class UpCollumn : public AbstractCollumn
{
public:
    UpCollumn(Ui::MainWindow* ui, NjambEngine& engine);

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

#endif // UPCOLLUMN_H
