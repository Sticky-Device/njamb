#include "upcollumn.h"

UpCollumn::UpCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{

}

ClickableLabel *UpCollumn::getUIElementOnes()
{
    return ui->label_up_ones;
}

ClickableLabel *UpCollumn::getUIElementTwos()
{
    return ui->label_up_twos;
}

ClickableLabel *UpCollumn::getUIElementThrees()
{
    return ui->label_up_threes;
}

ClickableLabel *UpCollumn::getUIElementFours()
{
    return ui->label_up_fours;
}

ClickableLabel *UpCollumn::getUIElementFives()
{
    return ui->label_up_fives;
}

ClickableLabel *UpCollumn::getUIElementSixes()
{
    return ui->label_up_sixes;
}

ClickableLabel *UpCollumn::getUIElementMax()
{
    return ui->label_up_max;
}

ClickableLabel *UpCollumn::getUIElementMin()
{
    return ui->label_up_min;
}

ClickableLabel *UpCollumn::getUIElementTriling()
{
    return ui->label_up_triling;
}

ClickableLabel *UpCollumn::getUIElementStraight()
{
    return ui->label_up_straight;
}

ClickableLabel *UpCollumn::getUIElementFull()
{
    return ui->label_up_full;
}

ClickableLabel *UpCollumn::getUIElementPoker()
{
    return ui->label_up_poker;
}

ClickableLabel *UpCollumn::getUIElementYamb()
{
    return ui->label_up_yamb;
}
