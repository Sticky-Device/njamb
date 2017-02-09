#include "UpDownCollumn.h"

static std::stack<Rules::YambField> defaultUpFields ( std::deque<Rules::YambField> {Rules::YambField::Ones, Rules::YambField::Twos, Rules::YambField::Threes, Rules::YambField::Fours,
                                                                                    Rules::YambField::Fives, Rules::YambField::Sixes, Rules::YambField::Max,
                                                                                   });

static std::stack<Rules::YambField> defaultDownFields { std::deque<Rules::YambField> {Rules::YambField::Yamb, Rules::YambField::Poker, Rules::YambField::Full,
                                                                                      Rules::YambField::Straight, Rules::YambField::Triling, Rules::YambField::Min
                                                                                     }};

UpDownCollumn::UpDownCollumn(Ui::MainWindow *ui, NjambEngine &engine, Results &results) :
    AbstractCollumn(ui, engine, results), playableUpFields(defaultUpFields), playableDownFields(defaultDownFields)
{}

void UpDownCollumn::reset()
{
    AbstractCollumn::reset();
    getUIElementOnes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementTwos()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementThrees()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFours()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFives()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementSixes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementTriling()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementStraight()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFull()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementPoker()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementYamb()->setStyleSheet(Rules::FILLED_LABEL_COLOR);

    playableUpFields = defaultUpFields;
    playableDownFields = defaultDownFields;
}

std::vector<Rules::YambField> UpDownCollumn::getPlayableFields()
{
    if (engine.getMode() == Rules::Mode::Called)
        return {};

    std::vector<Rules::YambField> result;
    if (!playableUpFields.empty())
        result.push_back(playableUpFields.top());
    if (!playableDownFields.empty())
        result.push_back(playableDownFields.top());

    return result;
}

void UpDownCollumn::fieldClicked(Rules::YambField field)
{
    if (!playableUpFields.empty() && (field == playableUpFields.top()))
        playableUpFields.pop();
    if (!playableDownFields.empty() && (field == playableDownFields.top()))
        playableDownFields.pop();

    AbstractCollumn::fieldClicked(field);
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

Rules::Collumn UpDownCollumn::getCollumn()
{
    return Rules::Collumn::UpDown;
}
