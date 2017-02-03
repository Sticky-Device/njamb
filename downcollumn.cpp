#include "downcollumn.h"

DownCollumn::DownCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine),
playableFields ( std::deque<Rules::YambField> {Rules::YambField::Yamb, Rules::YambField::Poker, Rules::YambField::Full,
                      Rules::YambField::Straight, Rules::YambField::Triling, Rules::YambField::Min, Rules::YambField::Max,
                      Rules::YambField::Sixes, Rules::YambField::Fives, Rules::YambField::Fours, Rules::YambField::Threes,
                      Rules::YambField::Twos, Rules::YambField::Ones
                   })
{
}

void DownCollumn::reset()
{
    AbstractCollumn::reset();
    getUIElementTwos()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementThrees()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFours()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFives()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementSixes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementMax()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementMin()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementTriling()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementStraight()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFull()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementPoker()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementYamb()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
}

std::vector<Rules::YambField> DownCollumn::getPlayableFields()
{
    return {playableFields.top()};
}

void DownCollumn::onesClicked()
{
    AbstractCollumn::onesClicked();
    playableFields.pop();
}

void DownCollumn::twosClicked()
{
    AbstractCollumn::twosClicked();
    playableFields.pop();
}

void DownCollumn::threesClicked()
{
    AbstractCollumn::threesClicked();
    playableFields.pop();
}

void DownCollumn::foursClicked()
{
    AbstractCollumn::foursClicked();
    playableFields.pop();
}

void DownCollumn::fivesClicked()
{
    AbstractCollumn::fivesClicked();
    playableFields.pop();
}

void DownCollumn::sixesClicked()
{
    AbstractCollumn::sixesClicked();
    playableFields.pop();
}

void DownCollumn::maxClicked()
{
    AbstractCollumn::maxClicked();
    playableFields.pop();
}

void DownCollumn::minClicked()
{
    AbstractCollumn::minClicked();
    playableFields.pop();
}

void DownCollumn::trilingClicked()
{
    AbstractCollumn::trilingClicked();
    playableFields.pop();
}

void DownCollumn::straightClicked()
{
    AbstractCollumn::straightClicked();
    playableFields.pop();
}

void DownCollumn::fullClicked()
{
    AbstractCollumn::fullClicked();
    playableFields.pop();
}

void DownCollumn::pokerClicked()
{
    AbstractCollumn::pokerClicked();
    playableFields.pop();
}

void DownCollumn::yambClicked()
{
    AbstractCollumn::yambClicked();
    playableFields.pop();
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
