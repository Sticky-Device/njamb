#ifndef DOWNCOLLUMN_H
#define DOWNCOLLUMN_H

#include "abstractcollumn.h"
#include <stack>

class DownCollumn : public AbstractCollumn
{
public:
    DownCollumn(Ui::MainWindow *ui, NjambEngine&);

public:
    void reset() override;
    std::vector<Rules::YambField> getPlayableFields() override;
    void fieldClicked(Rules::YambField field) override;

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

private:
    std::stack<Rules::YambField> playableFields;
};

#endif // DOWNCOLLUMN_H
