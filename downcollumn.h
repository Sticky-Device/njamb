#ifndef DOWNCOLLUMN_H
#define DOWNCOLLUMN_H

#include "abstractcollumn.h"

class DownCollumn : public AbstractCollumn
{
public:
    DownCollumn(Ui::MainWindow *ui, NjambEngine&);

public:
    void reset() override;

public:
    ClickableLabel *getUIElementOnes() override;
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

#endif // DOWNCOLLUMN_H
