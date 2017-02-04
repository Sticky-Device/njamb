#include "downcollumn.h"

static std::stack<Rules::YambField> defaultFields ( std::deque<Rules::YambField> {Rules::YambField::Yamb, Rules::YambField::Poker, Rules::YambField::Full,
                                                                                    Rules::YambField::Straight, Rules::YambField::Triling, Rules::YambField::Min, Rules::YambField::Max,
                                                                                    Rules::YambField::Sixes, Rules::YambField::Fives, Rules::YambField::Fours, Rules::YambField::Threes,
                                                                                    Rules::YambField::Twos, Rules::YambField::Ones
                                                                                 });

DownCollumn::DownCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine), playableFields(defaultFields)
{}

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

    playableFields = defaultFields;
}

std::vector<Rules::YambField> DownCollumn::getPlayableFields()
{
    return {playableFields.top()};
}

void DownCollumn::fieldClicked(Rules::YambField field)
{
    playableFields.pop();
    AbstractCollumn::fieldClicked(field);
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
