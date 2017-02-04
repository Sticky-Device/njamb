#ifndef ABSTRACTCOLLUMN_H
#define ABSTRACTCOLLUMN_H

#include "ui_mainwindow.h"
#include "njambengine.h"
#include "clickablelabel.h"
#include "rules.h"
#include <vector>

class AbstractCollumn
{
public:
    AbstractCollumn(Ui::MainWindow *ui, NjambEngine&);

    virtual void diceRolled();
    virtual void updateFields();
    virtual void reset();
    virtual void nextRound();
    virtual std::vector<Rules::YambField> getPlayableFields() = 0;

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

public:
    // field events
    virtual void onesHovered();
    virtual void onesUnhovered();
    virtual void onesClicked();

    virtual void twosHovered();
    virtual void twosUnhovered();
    virtual void twosClicked();

    virtual void threesHovered();
    virtual void threesUnhovered();
    virtual void threesClicked();

    virtual void foursHovered();
    virtual void foursUnhovered();
    virtual void foursClicked();

    virtual void fivesHovered();
    virtual void fivesUnhovered();
    virtual void fivesClicked();

    virtual void sixesHovered();
    virtual void sixesUnhovered();
    virtual void sixesClicked();

    virtual void maxHovered();
    virtual void maxUnhovered();
    virtual void maxClicked();

    virtual void minHovered();
    virtual void minUnhovered();
    virtual void minClicked();

    virtual void trilingHovered();
    virtual void trilingUnhovered();
    virtual void trilingClicked();

    virtual void straightHovered();
    virtual void straightUnhovered();
    virtual void straightClicked();

    virtual void fullHovered();
    virtual void fullUnhovered();
    virtual void fullClicked();

    virtual void pokerHovered();
    virtual void pokerUnhovered();
    virtual void pokerClicked();

    virtual void yambHovered();
    virtual void yambUnhovered();
    virtual void yambClicked();

protected:
    Ui::MainWindow *ui;
    NjambEngine& engine;
};

#endif // ABSTRACTCOLLUMN_H
