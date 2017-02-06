#include "callcollumn.h"

CallCollumn::CallCollumn(Ui::MainWindow *ui, NjambEngine &engine, Results &results) :
    AbstractCollumn(ui, engine, results)
{}

std::vector<Rules::YambField> CallCollumn::getPlayableFields()
{
    std::vector<Rules::YambField> playableFields;
    switch (state.mode) {
    case CallCollumnMode::Normal:
        // TODO: use set_difference on allFields and filledFields
        std::copy_if(begin(allFields), end(allFields), std::back_inserter(playableFields), [&](Rules::YambField field) {
            return std::none_of(begin(filledFields), end(filledFields), [&] (Rules::YambField filledField) {
                return field == filledField;
            });
        });
        break;
    case CallCollumnMode::Called:
        playableFields.push_back(state.calledField);
        break;
    default:
        break;
    }

    return playableFields;
}

void CallCollumn::fieldClicked(Rules::YambField field)
{
    switch (state.mode) {
    case CallCollumnMode::Normal :
        state = {CallCollumnMode::Called, field};
        updateFields();
        break;
    case CallCollumnMode::Called :
        state = {CallCollumnMode::Normal, Rules::YambField::None};
        filledFields.push_back(field);
        AbstractCollumn::fieldClicked(field);
    default:
        break;
    }
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

Rules::Collumn CallCollumn::getCollumn()
{
    return Rules::Collumn::Call;
}
