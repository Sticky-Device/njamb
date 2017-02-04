#include "handcollumn.h"

HandCollumn::HandCollumn(Ui::MainWindow *ui, NjambEngine &engine) : AbstractCollumn(ui, engine)
{
}

std::vector<Rules::YambField> HandCollumn::getPlayableFields()
{
    playableFields.clear();
    if (engine.currentRoll() == 1)
    {
        // we can change hand collumn only in
        // TODO: test scenario when at the end of game you are left only with fields from hand collumn
        //       in that scenario user should not be allowed to roll dice second/third time
        std::copy_if(begin(allFields), end(allFields), std::back_inserter(playableFields), [&](Rules::YambField field) {
            return std::none_of(begin(filledFields), end(filledFields), [&] (Rules::YambField filledField) {
                return field == filledField;
            });
        });
    }

    return playableFields;
}

void HandCollumn::fieldClicked(Rules::YambField field)
{
    filledFields.push_back(field);
    AbstractCollumn::fieldClicked(field);
}

void HandCollumn::removePlayableField(Rules::YambField field)
{
    playableFields.erase(std::remove(playableFields.begin(), playableFields.end(), field), playableFields.end());
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
