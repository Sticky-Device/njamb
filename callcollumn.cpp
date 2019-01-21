#include "callcollumn.h"

CallCollumn::CallCollumn(Ui::MainWindow *ui, NjambEngine &engine, Results &results) :
    AbstractCollumn(ui, engine, results)
{}

void CallCollumn::reset()
{
    filledFields.clear();
    calledField = Rules::YambField::None;
    AbstractCollumn::reset();
}

std::vector<Rules::YambField> CallCollumn::getPlayableFields()
{
    if ((engine.currentRoll() > 1) && (engine.getMode() != Rules::Mode::Called))
        return {};

    std::vector<Rules::YambField> playableFields;
    switch (engine.getMode()) {
    case Rules::Mode::Normal:
        // TODO: use set_difference on allFields and filledFields
        std::copy_if(begin(allFields), end(allFields), std::back_inserter(playableFields), [&](Rules::YambField field) {
            return std::none_of(begin(filledFields), end(filledFields), [&] (Rules::YambField filledField) {
                return field == filledField;
            });
        });
        break;
    case Rules::Mode::Called:
        playableFields.push_back(calledField);
        break;
    }

    return playableFields;
}

void CallCollumn::fieldClicked(Rules::YambField field)
{
    switch (engine.getMode()) {
    case Rules::Mode::Normal :
        engine.CallFieldClicked();
        calledField = field;
        updateFields();
        break;
    case Rules::Mode::Called :
        if (calledField == field)// submit selected
        {
            engine.CallFieldClicked();
            calledField = Rules::YambField::None;
            filledFields.push_back(field);
            AbstractCollumn::fieldClicked(field);
        }
        else // call choice changed
        {
            calledField = field;
            updateFields();
        }
        break;
    }
}

void CallCollumn::updateFields()
{
    AbstractCollumn::updateFields();
    for (auto field : allFields)
        getUIElement(field)->setActive(true);
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
