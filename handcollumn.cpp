#include "handcollumn.h"

HandCollumn::HandCollumn(Ui::MainWindow *ui, NjambEngine &engine, Results &results) : AbstractCollumn(ui, engine, results)
{
}

std::vector<Rules::YambField> HandCollumn::getPlayableFields()
{
    if ((engine.currentRoll() > 1) || (engine.getMode() == Rules::Mode::Called))
        return {};

    std::vector<Rules::YambField> playableFields;
    // we can change hand collumn only in
    // TODO: test scenario when at the end of game you are left only with fields from hand collumn
    //       in that scenario user should not be allowed to roll dice second/third time
    // TODO: use set_difference
    std::copy_if(begin(allFields), end(allFields), std::back_inserter(playableFields), [&](Rules::YambField field) {
        return std::none_of(begin(filledFields), end(filledFields), [&] (Rules::YambField filledField) {
            return field == filledField;
        });
    });

    return playableFields;
}

void HandCollumn::fieldClicked(Rules::YambField field)
{
    filledFields.push_back(field);
    AbstractCollumn::fieldClicked(field);
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

Rules::Collumn HandCollumn::getCollumn()
{
    return Rules::Collumn::Hand;
}
