#ifndef ABSTRACTCOLLUMN_H
#define ABSTRACTCOLLUMN_H

#include "ui_mainwindow.h"
#include "njambengine.h"
#include "clickablelabel.h"
#include "rules.h"
#include "results.h"
#include <vector>

class AbstractCollumn
{
public:
    AbstractCollumn(Ui::MainWindow *ui, NjambEngine&, Results& results);

    virtual void diceRolled();
    virtual void updateFields();
    virtual void reset();
    virtual void nextRound();
    virtual std::vector<Rules::YambField> getPlayableFields() = 0;
    virtual void fieldHovered(Rules::YambField);
    virtual void fieldUnhovered(Rules::YambField);
    virtual void fieldClicked(Rules::YambField);
    virtual void callFieldSelected();

public:
    // abstract methods
    virtual ClickableLabel* getUIElementOnes() = 0;
    virtual ClickableLabel* getUIElementTwos() = 0;
    virtual ClickableLabel* getUIElementThrees() = 0;
    virtual ClickableLabel* getUIElementFours() = 0;
    virtual ClickableLabel* getUIElementFives() = 0;
    virtual ClickableLabel* getUIElementSixes() = 0;
    virtual ClickableLabel* getUIElementMax() = 0;
    virtual ClickableLabel* getUIElementMin() = 0;
    virtual ClickableLabel* getUIElementTriling() = 0;
    virtual ClickableLabel* getUIElementStraight() = 0;
    virtual ClickableLabel* getUIElementFull() = 0;
    virtual ClickableLabel* getUIElementPoker() = 0;
    virtual ClickableLabel* getUIElementYamb() = 0;

protected:
    virtual Rules::Collumn getCollumn() = 0;

protected:
    Ui::MainWindow *ui;
    NjambEngine& engine;
    Results& results;
    static const std::vector<Rules::YambField> allFields;

private:
    ClickableLabel *getUIElement(Rules::YambField);
};

#endif // ABSTRACTCOLLUMN_H
