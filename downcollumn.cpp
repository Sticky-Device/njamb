#include "downcollumn.h"

DownCollumn::DownCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{

}

ClickableLabel *DownCollumn::getUIElementOnes()
{
    return ui->label_down_ones;
}

ClickableLabel *DownCollumn::getUIElementTwos()
{
    return ui->label_down_twos;
}

ClickableLabel *DownCollumn::getUIElementThrees()
{
    return ui->label_down_threes;
}

ClickableLabel *DownCollumn::getUIElementFours()
{
    return ui->label_down_fours;
}

ClickableLabel *DownCollumn::getUIElementFives()
{
    return ui->label_down_fives;
}

ClickableLabel *DownCollumn::getUIElementSixes()
{
    return ui->label_down_sixes;
}

ClickableLabel *DownCollumn::getUIElementMax()
{
    return ui->label_down_max;
}

ClickableLabel *DownCollumn::getUIElementMin()
{
    return ui->label_down_min;
}

ClickableLabel *DownCollumn::getUIElementTriling()
{
    return ui->label_down_triling;
}

ClickableLabel *DownCollumn::getUIElementStraight()
{
    return ui->label_down_straight;
}

ClickableLabel *DownCollumn::getUIElementFull()
{
    return ui->label_down_full;
}

ClickableLabel *DownCollumn::getUIElementPoker()
{
    return ui->label_down_poker;
}

ClickableLabel *DownCollumn::getUIElementYamb()
{
    return ui->label_down_yamb;
}
