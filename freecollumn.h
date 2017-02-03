#ifndef FREECOLLUMN_H
#define FREECOLLUMN_H

#include "abstractcollumn.h"

class FreeCollumn : public AbstractCollumn
{
public:
    FreeCollumn(Ui::MainWindow* ui, NjambEngine& engine);

public:
    std::vector<Rules::YambField> getPlayableFields() override;

public:
    void onesClicked();
    void twosClicked();
    void threesClicked();
    void foursClicked();
    void fivesClicked();
    void sixesClicked();
    void maxClicked();
    void minClicked();
    void trilingClicked();
    void straightClicked();
    void fullClicked();
    void pokerClicked();
    void yambClicked();

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
    void removePlayableField(Rules::YambField field);

private:
    std::vector<Rules::YambField> playableFields;
};

#endif // FREECOLLUMN_H
