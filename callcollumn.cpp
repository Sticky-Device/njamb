#include "callcollumn.h"

CallCollumn::CallCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{

}

ClickableLabel *CallCollumn::getUIElementOnes()
{
    return ui->label_call_ones;
}

ClickableLabel *CallCollumn::getUIElementTwos()
{
    return ui->label_call_twos;
}

ClickableLabel *CallCollumn::getUIElementThrees()
{
    return ui->label_call_threes;
}

ClickableLabel *CallCollumn::getUIElementFours()
{
    return ui->label_call_fours;
}

ClickableLabel *CallCollumn::getUIElementFives()
{
    return ui->label_call_fives;
}

ClickableLabel *CallCollumn::getUIElementSixes()
{
    return ui->label_call_sixes;
}

ClickableLabel *CallCollumn::getUIElementMax()
{
    return ui->label_call_max;
}

ClickableLabel *CallCollumn::getUIElementMin()
{
    return ui->label_call_min;
}

ClickableLabel *CallCollumn::getUIElementTriling()
{
    return ui->label_call_triling;
}

ClickableLabel *CallCollumn::getUIElementStraight()
{
    return ui->label_call_straight;
}

ClickableLabel *CallCollumn::getUIElementFull()
{
    return ui->label_call_full;
}

ClickableLabel *CallCollumn::getUIElementPoker()
{
    return ui->label_call_poker;
}

ClickableLabel *CallCollumn::getUIElementYamb()
{
    return ui->label_call_yamb;
}
