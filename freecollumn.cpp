#include "freecollumn.h"

FreeCollumn::FreeCollumn(Ui::MainWindow* ui, NjambEngine& engine) : AbstractCollumn(ui, engine)
{
    playableFields = {Rules::YambField::Ones, Rules::YambField::Twos, Rules::YambField::Threes, Rules::YambField::Fours,
                      Rules::YambField::Fives, Rules::YambField::Sixes, Rules::YambField::Max, Rules::YambField::Min,
                      Rules::YambField::Triling, Rules::YambField::Straight, Rules::YambField::Full,
                      Rules::YambField::Poker, Rules::YambField::Yamb
                     };
}

void FreeCollumn::onesClicked()
{
    AbstractCollumn::onesClicked();
    removePlayableField(Rules::YambField::Ones);
}

void FreeCollumn::twosClicked()
{
    AbstractCollumn::twosClicked();
    removePlayableField(Rules::YambField::Twos);
}

void FreeCollumn::threesClicked()
{
    AbstractCollumn::threesClicked();
    removePlayableField(Rules::YambField::Threes);
}

void FreeCollumn::foursClicked()
{
    AbstractCollumn::foursClicked();
    removePlayableField(Rules::YambField::Fours);
}

void FreeCollumn::fivesClicked()
{
    AbstractCollumn::fivesClicked();
    removePlayableField(Rules::YambField::Fives);
}

void FreeCollumn::sixesClicked()
{
    AbstractCollumn::sixesClicked();
    removePlayableField(Rules::YambField::Sixes);
}

void FreeCollumn::maxClicked()
{
    AbstractCollumn::maxClicked();
    removePlayableField(Rules::YambField::Max);
}

void FreeCollumn::minClicked()
{
    AbstractCollumn::minClicked();
    removePlayableField(Rules::YambField::Min);
}

void FreeCollumn::trilingClicked()
{
    AbstractCollumn::trilingClicked();
    removePlayableField(Rules::YambField::Triling);
}

void FreeCollumn::straightClicked()
{
    AbstractCollumn::straightClicked();
    removePlayableField(Rules::YambField::Straight);
}

void FreeCollumn::fullClicked()
{
    AbstractCollumn::fullClicked();
    removePlayableField(Rules::YambField::Full);
}

void FreeCollumn::pokerClicked()
{
    AbstractCollumn::pokerClicked();
    removePlayableField(Rules::YambField::Poker);
}

void FreeCollumn::yambClicked()
{
    AbstractCollumn::yambClicked();
    removePlayableField(Rules::YambField::Yamb);
}


std::vector<Rules::YambField> FreeCollumn::getPlayableFields()
{
    return playableFields;
}

ClickableLabel *FreeCollumn::getUIElementOnes()
{
    return ui->label_free_ones;
}

ClickableLabel *FreeCollumn::getUIElementTwos()
{
    return ui->label_free_twos;
}

ClickableLabel *FreeCollumn::getUIElementThrees()
{
    return ui->label_free_threes;
}

ClickableLabel *FreeCollumn::getUIElementFours()
{
    return ui->label_free_fours;
}

ClickableLabel *FreeCollumn::getUIElementFives()
{
    return ui->label_free_fives;
}

ClickableLabel *FreeCollumn::getUIElementSixes()
{
    return ui->label_free_sixes;
}

ClickableLabel *FreeCollumn::getUIElementMax()
{
    return ui->label_free_max;
}

ClickableLabel *FreeCollumn::getUIElementMin()
{
    return ui->label_free_min;
}

ClickableLabel *FreeCollumn::getUIElementTriling()
{
    return ui->label_free_triling;
}

ClickableLabel *FreeCollumn::getUIElementStraight()
{
    return ui->label_free_straight;
}

ClickableLabel *FreeCollumn::getUIElementFull()
{
    return ui->label_free_full;
}

ClickableLabel *FreeCollumn::getUIElementPoker()
{
    return ui->label_free_poker;
}

ClickableLabel *FreeCollumn::getUIElementYamb()
{
    return ui->label_free_yamb;
}

void FreeCollumn::removePlayableField(Rules::YambField field)
{
    playableFields.erase(std::remove(playableFields.begin(), playableFields.end(), field), playableFields.end());
}
