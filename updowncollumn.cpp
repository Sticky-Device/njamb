#include "upUpDownCollumn.h"

UpUpDownCollumn::UpUpDownCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{

}

ClickableLabel *UpDownCollumn::getUIElementOnes()
{
    return ui->label_updown_ones;
}

ClickableLabel *UpDownCollumn::getUIElementTwos()
{
    return ui->label_updown_twos;
}

ClickableLabel *UpDownCollumn::getUIElementThrees()
{
    return ui->label_updown_threes;
}

ClickableLabel *UpDownCollumn::getUIElementFours()
{
    return ui->label_updown_fours;
}

ClickableLabel *UpDownCollumn::getUIElementFives()
{
    return ui->label_updown_fives;
}

ClickableLabel *UpDownCollumn::getUIElementSixes()
{
    return ui->label_updown_sixes;
}

ClickableLabel *UpDownCollumn::getUIElementMax()
{
    return ui->label_updown_max;
}

ClickableLabel *UpDownCollumn::getUIElementMin()
{
    return ui->label_updown_min;
}

ClickableLabel *UpDownCollumn::getUIElementTriling()
{
    return ui->label_updown_triling;
}

ClickableLabel *UpDownCollumn::getUIElementStraight()
{
    return ui->label_updown_straight;
}

ClickableLabel *UpDownCollumn::getUIElementFull()
{
    return ui->label_updown_full;
}

ClickableLabel *UpDownCollumn::getUIElementPoker()
{
    return ui->label_updown_poker;
}

ClickableLabel *UpDownCollumn::getUIElementYamb()
{
    return ui->label_updown_yamb;
}
