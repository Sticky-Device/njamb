#include "handcollumn.h"

HandCollumn::HandCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{

}

ClickableLabel *HandCollumn::getUIElementOnes()
{
    return ui->label_hand_ones;
}

ClickableLabel *HandCollumn::getUIElementTwos()
{
    return ui->label_hand_twos;
}

ClickableLabel *HandCollumn::getUIElementThrees()
{
    return ui->label_hand_threes;
}

ClickableLabel *HandCollumn::getUIElementFours()
{
    return ui->label_hand_fours;
}

ClickableLabel *HandCollumn::getUIElementFives()
{
    return ui->label_hand_fives;
}

ClickableLabel *HandCollumn::getUIElementSixes()
{
    return ui->label_hand_sixes;
}

ClickableLabel *HandCollumn::getUIElementMax()
{
    return ui->label_hand_max;
}

ClickableLabel *HandCollumn::getUIElementMin()
{
    return ui->label_hand_min;
}

ClickableLabel *HandCollumn::getUIElementTriling()
{
    return ui->label_hand_triling;
}

ClickableLabel *HandCollumn::getUIElementStraight()
{
    return ui->label_hand_straight;
}

ClickableLabel *HandCollumn::getUIElementFull()
{
    return ui->label_hand_full;
}

ClickableLabel *HandCollumn::getUIElementPoker()
{
    return ui->label_hand_poker;
}

ClickableLabel *HandCollumn::getUIElementYamb()
{
    return ui->label_hand_yamb;
}
