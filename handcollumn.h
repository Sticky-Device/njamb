#ifndef HANDCOLLUMN_H
#define HANDCOLLUMN_H

#include "abstractcollumn.h"

class HandCollumn : public AbstractCollumn
{
public:
    HandCollumn(Ui::MainWindow* ui, NjambEngine& engine, Results &results);

public:
    std::vector<Rules::YambField> getPlayableFields() override;
    void fieldClicked(Rules::YambField field) override;

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
    void removePlayableField(Rules::YambField field);

private:
    std::vector<Rules::YambField> playableFields;
    std::vector<Rules::YambField> filledFields;
};

#endif // HANDCOLLUMN_H
