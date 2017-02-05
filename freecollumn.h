#ifndef FREECOLLUMN_H
#define FREECOLLUMN_H

#include "abstractcollumn.h"

class FreeCollumn : public AbstractCollumn
{
public:
    FreeCollumn(Ui::MainWindow* ui, NjambEngine& engine, Results &results);

public:
    void reset() override;
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
};

#endif // FREECOLLUMN_H
