#ifndef ABSTRACTCOLLUMN_H
#define ABSTRACTCOLLUMN_H

#include "ui_mainwindow.h"
#include "njambengine.h"
#include "clickablelabel.h"

class AbstractCollumn
{
public:
    AbstractCollumn(Ui::MainWindow *ui, NjambEngine&);

    virtual void diceRolled();
    virtual void reset();

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
    void onesHovered();
    void onesUnhovered();
    void onesClicked();

    void twosHovered();
    void twosUnhovered();
    void twosClicked();

    void threesHovered();
    void threesUnhovered();
    void threesClicked();

    void foursHovered();
    void foursUnhovered();
    void foursClicked();

    void fivesHovered();
    void fivesUnhovered();
    void fivesClicked();

    void sixesHovered();
    void sixesUnhovered();
    void sixesClicked();

    void maxHovered();
    void maxUnhovered();
    void maxClicked();

    void minHovered();
    void minUnhovered();
    void minClicked();

    void trilingHovered();
    void trilingUnhovered();
    void trilingClicked();

    void straightHovered();
    void straightUnhovered();
    void straightClicked();

    void fullHovered();
    void fullUnhovered();
    void fullClicked();

    void pokerHovered();
    void pokerUnhovered();
    void pokerClicked();

    void yambHovered();
    void yambUnhovered();
    void yambClicked();

protected:
    Ui::MainWindow *ui;
    NjambEngine& engine;
private slots:
    void on_label_down_ones_hovered();
    void on_label_down_ones_unhovered();
    void on_label_down_ones_clicked();
    void on_label_down_twos_hovered();
    void on_label_down_twos_unhovered();
    void on_label_down_twos_clicked();
    void on_label_down_threes_hovered();
    void on_label_down_threes_unhovered();
    void on_label_down_threes_clicked();
};

#endif // ABSTRACTCOLLUMN_H
