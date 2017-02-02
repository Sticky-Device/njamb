#include "freecollumn.h"

FreeCollumn::FreeCollumn(Ui::MainWindow* ui, NjambEngine& engine) : AbstractCollumn(ui, engine)
{

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
