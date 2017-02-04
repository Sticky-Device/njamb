#include "upcollumn.h"

static std::stack<Rules::YambField> defaultFields ( std::deque<Rules::YambField> {Rules::YambField::Ones, Rules::YambField::Twos, Rules::YambField::Threes, Rules::YambField::Fours,
                  Rules::YambField::Fives, Rules::YambField::Sixes, Rules::YambField::Max, Rules::YambField::Min,
                  Rules::YambField::Triling, Rules::YambField::Straight, Rules::YambField::Full,
                  Rules::YambField::Poker, Rules::YambField::Yamb
                 });

UpCollumn::UpCollumn(Ui::MainWindow *ui, NjambEngine &engine, Results &results) : AbstractCollumn(ui, engine, results), playableFields(defaultFields)
{}

void UpCollumn::reset()
{
    AbstractCollumn::reset();
    getUIElementOnes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
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

    playableFields = defaultFields;
}

std::vector<Rules::YambField> UpCollumn::getPlayableFields()
{
    if (playableFields.empty())
        return {};

    return {playableFields.top()};
}

void UpCollumn::fieldClicked(Rules::YambField field)
{
    playableFields.pop();
    AbstractCollumn::fieldClicked(field);
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

Rules::Collumn UpCollumn::getCollumn()
{
    return Rules::Collumn::Up;
}
