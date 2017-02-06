#ifndef CALLCOLLUMN_H
#define CALLCOLLUMN_H

#include "abstractcollumn.h"

enum class CallCollumnMode
{
    Normal,
    Called
};

struct CallCollumnState
{
    CallCollumnMode mode;
    Rules::YambField calledField;
};

class CallCollumn : public AbstractCollumn
{
public:
    CallCollumn(Ui::MainWindow* ui, NjambEngine& engine, Results &results);

public:
    std::vector<Rules::YambField> getPlayableFields() override;
    void fieldClicked(Rules::YambField field) override;

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

private:
    std::vector<Rules::YambField> filledFields;
    CallCollumnState state = { CallCollumnMode::Normal, Rules::YambField::None};
};

#endif // CALLCOLLUMN_H
