#include "abstractcollumn.h"
#include "rules.h"

const std::vector<Rules::YambField> AbstractCollumn::allFields {Rules::YambField::Ones, Rules::YambField::Twos, Rules::YambField::Threes, Rules::YambField::Fours,
                                                                Rules::YambField::Fives, Rules::YambField::Sixes, Rules::YambField::Max, Rules::YambField::Min,
                                                                Rules::YambField::Triling, Rules::YambField::Straight, Rules::YambField::Full,
                                                                Rules::YambField::Poker, Rules::YambField::Yamb
                                                               };

AbstractCollumn::AbstractCollumn(Ui::MainWindow *ui, NjambEngine & eng) : ui(ui), engine(eng)
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
    getUIElementOnes()->reset();
    getUIElementOnes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementTwos()->reset();
    getUIElementTwos()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementThrees()->reset();
    getUIElementThrees()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFours()->reset();
    getUIElementFours()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFives()->reset();
    getUIElementFives()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementSixes()->reset();
    getUIElementSixes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementMax()->reset();
    getUIElementMax()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementMin()->reset();
    getUIElementMin()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementTriling()->reset();
    getUIElementTriling()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementStraight()->reset();
    getUIElementStraight()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFull()->reset();
    getUIElementFull()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementPoker()->reset();
    getUIElementPoker()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementYamb()->reset();
    getUIElementYamb()->setStyleSheet(Rules::FREE_LABEL_COLOR);
}

void AbstractCollumn::nextRound()
{
    getUIElementOnes()->setActive(false);
    getUIElementTwos()->setActive(false);
    getUIElementThrees()->setActive(false);
    getUIElementFours()->setActive(false);
    getUIElementFives()->setActive(false);
    getUIElementSixes()->setActive(false);
    getUIElementMax()->setActive(false);
    getUIElementMin()->setActive(false);
    getUIElementTriling()->setActive(false);
    getUIElementStraight()->setActive(false);
    getUIElementFull()->setActive(false);
    getUIElementPoker()->setActive(false);
    getUIElementYamb()->setActive(false);
}

void AbstractCollumn::fieldHovered(Rules::YambField field)
{
    auto hand = engine.getCurrentHand();
    getUIElement(field)->setText(QString::number(hand.getBestResult(field)));
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
    return getUIElementOnes();
}
