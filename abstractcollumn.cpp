#include "abstractcollumn.h"
#include "rules.h"

const std::vector<Rules::YambField> AbstractCollumn::allFields {Rules::YambField::Ones, Rules::YambField::Twos, Rules::YambField::Threes, Rules::YambField::Fours,
                                                                Rules::YambField::Fives, Rules::YambField::Sixes, Rules::YambField::Max, Rules::YambField::Min,
                                                                Rules::YambField::Triling, Rules::YambField::Straight, Rules::YambField::Full,
                                                                Rules::YambField::Poker, Rules::YambField::Yamb
                                                               };

AbstractCollumn::AbstractCollumn(Ui::MainWindow *ui, NjambEngine & eng, Results &results) : ui(ui), engine(eng), results(results)
{

}

void AbstractCollumn::diceRolled()
{
    updateFields();
}

void AbstractCollumn::updateFields()
{
    auto playableFields = getPlayableFields();
    for (auto field : allFields)
    {
        if (std::find(begin(playableFields), end(playableFields), field) != end(playableFields))
        {
            getUIElement(field)->setActive(true);
            getUIElement(field)->setStyleSheet(Rules::FREE_LABEL_COLOR);
        }
        else
        {
            getUIElement(field)->setActive(false);
            getUIElement(field)->setStyleSheet(Rules::FILLED_LABEL_COLOR);
        }
    }
}

void AbstractCollumn::reset()
{
    for (auto field : allFields)
    {
        getUIElement(field)->reset();
        getUIElement(field)->setStyleSheet(Rules::FREE_LABEL_COLOR);
    }
}

void AbstractCollumn::nextRound()
{
    for (auto field : allFields)
    {
        getUIElement(field)->setActive(false);
    }
}

void AbstractCollumn::fieldHovered(Rules::YambField field)
{
    auto hand = engine.getCurrentHand();
    auto currentRoll = engine.currentRoll();
    getUIElement(field)->setText(QString::number(hand.getBestResult(field, currentRoll)));
}

void AbstractCollumn::fieldUnhovered(Rules::YambField field)
{
    getUIElement(field)->setText("");
}

void AbstractCollumn::fieldClicked(Rules::YambField field)
{   
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(field, engine.currentRoll());
    getUIElement(field)->setText(QString::number(result));
    getUIElement(field)->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElement(field)->setFilled(true);
    results.updateResult(getCollumn(), field, result);
    updateFields();
}

ClickableLabel *AbstractCollumn::getUIElement(Rules::YambField field)
{
    switch (field) {
    case Rules::YambField::Ones:
        return getUIElementOnes();
    case Rules::YambField::Twos:
        return getUIElementTwos();
    case Rules::YambField::Threes:
        return getUIElementThrees();
    case Rules::YambField::Fours:
        return getUIElementFours();
    case Rules::YambField::Fives:
        return getUIElementFives();
    case Rules::YambField::Sixes:
        return getUIElementSixes();
    case Rules::YambField::Max:
        return getUIElementMax();
    case Rules::YambField::Min:
        return getUIElementMin();
    case Rules::YambField::Triling:
        return getUIElementTriling();
    case Rules::YambField::Straight:
        return getUIElementStraight();
    case Rules::YambField::Full:
        return getUIElementFull();
    case Rules::YambField::Poker:
        return getUIElementPoker();
    case Rules::YambField::Yamb:
        return getUIElementYamb();
    default:
        break;
    }

    // should not get here
    // TODO: add assertion.
    // Unfortunately, we can't simply return address of some randomly created ClickableLabel, as it's not bound to any "real" UI object.
    // Therefore QT complains when such object is created, and app crashes. To be investigated further.
    return getUIElementOnes();
}
