#include "abstractcollumn.h"
#include "rules.h"

AbstractCollumn::AbstractCollumn(Ui::MainWindow *ui, NjambEngine & eng) : ui(ui), engine(eng)
{

}

void AbstractCollumn::diceRolled()
{
    updateFields();
}

void AbstractCollumn::updateFields()
{
    for (auto field : getPlayableFields())
    {
        switch (field) {
        case Rules::YambField::Ones:
            getUIElementOnes()->setActive(true);
            getUIElementOnes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Twos:
            getUIElementTwos()->setActive(true);
            getUIElementTwos()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Threes:
            getUIElementThrees()->setActive(true);
            getUIElementThrees()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Fours:
            getUIElementFours()->setActive(true);
            getUIElementFours()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Fives:
            getUIElementFives()->setActive(true);
            getUIElementFives()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Sixes:
            getUIElementSixes()->setActive(true);
            getUIElementSixes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Max:
            getUIElementMax()->setActive(true);
            getUIElementMax()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Min:
            getUIElementMin()->setActive(true);
            getUIElementMin()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Triling:
            getUIElementTriling()->setActive(true);
            getUIElementTriling()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Straight:
            getUIElementStraight()->setActive(true);
            getUIElementStraight()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Full:
            getUIElementFull()->setActive(true);
            getUIElementFull()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Poker:
            getUIElementPoker()->setActive(true);
            getUIElementPoker()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        case Rules::YambField::Yamb:
            getUIElementYamb()->setActive(true);
            getUIElementYamb()->setStyleSheet(Rules::FREE_LABEL_COLOR);
            break;
        default:
            break;
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

void AbstractCollumn::onesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementOnes()->setText(QString::number(hand.getBestResult(Rules::YambField::Ones)));
}

void AbstractCollumn::onesUnhovered()
{
    getUIElementOnes()->setText("");
}

void AbstractCollumn::onesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Ones);
    getUIElementOnes()->setText(QString::number(result));
    getUIElementOnes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementOnes()->setFilled(true);
}

void AbstractCollumn::twosHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementTwos()->setText(QString::number(hand.getBestResult(Rules::YambField::Twos)));
}

void AbstractCollumn::twosUnhovered()
{
    getUIElementTwos()->setText("");
}

void AbstractCollumn::twosClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Twos);
    getUIElementTwos()->setText(QString::number(result));
    getUIElementTwos()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementTwos()->setFilled(true);
}

void AbstractCollumn::threesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementThrees()->setText(QString::number(hand.getBestResult(Rules::YambField::Threes)));
}

void AbstractCollumn::threesUnhovered()
{
    getUIElementThrees()->setText("");
}

void AbstractCollumn::threesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Threes);
    getUIElementThrees()->setText(QString::number(result));
    getUIElementThrees()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementThrees()->setFilled(true);
}

void AbstractCollumn::foursHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFours()->setText(QString::number(hand.getBestResult(Rules::YambField::Fours)));
}

void AbstractCollumn::foursUnhovered()
{
    getUIElementFours()->setText("");
}

void AbstractCollumn::foursClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fours);
    getUIElementFours()->setText(QString::number(result));
    getUIElementFours()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFours()->setFilled(true);
}

void AbstractCollumn::fivesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFives()->setText(QString::number(hand.getBestResult(Rules::YambField::Fives)));
}

void AbstractCollumn::fivesUnhovered()
{
    getUIElementFives()->setText("");
}

void AbstractCollumn::fivesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fives);
    getUIElementFives()->setText(QString::number(result));
    getUIElementFives()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFives()->setFilled(true);
}

void AbstractCollumn::sixesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementSixes()->setText(QString::number(hand.getBestResult(Rules::YambField::Sixes)));
}

void AbstractCollumn::sixesUnhovered()
{
    getUIElementSixes()->setText("");
}

void AbstractCollumn::sixesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Sixes);
    getUIElementSixes()->setText(QString::number(result));
    getUIElementSixes()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementSixes()->setFilled(true);
}

void AbstractCollumn::maxHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementMax()->setText(QString::number(hand.getBestResult(Rules::YambField::Max)));
}

void AbstractCollumn::maxUnhovered()
{
    getUIElementMax()->setText("");
}

void AbstractCollumn::maxClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Max);
    getUIElementMax()->setText(QString::number(result));
    getUIElementMax()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementMax()->setFilled(true);
}

void AbstractCollumn::minHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementMin()->setText(QString::number(hand.getBestResult(Rules::YambField::Min)));
}

void AbstractCollumn::minUnhovered()
{
    getUIElementMin()->setText("");
}

void AbstractCollumn::minClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Min);
    getUIElementMin()->setText(QString::number(result));
    getUIElementMin()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementMin()->setFilled(true);
}

void AbstractCollumn::trilingHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementTriling()->setText(QString::number(hand.getBestResult(Rules::YambField::Triling)));
}

void AbstractCollumn::trilingUnhovered()
{
    getUIElementTriling()->setText("");
}

void AbstractCollumn::trilingClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Triling);
    getUIElementTriling()->setText(QString::number(result));
    getUIElementTriling()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementTriling()->setFilled(true);
}

void AbstractCollumn::straightHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementStraight()->setText(QString::number(hand.getBestResult(Rules::YambField::Straight, engine.currentRoll())));
}

void AbstractCollumn::straightUnhovered()
{
    getUIElementStraight()->setText("");
}

void AbstractCollumn::straightClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Straight, engine.currentRoll());
    getUIElementStraight()->setText(QString::number(result));
    getUIElementStraight()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementStraight()->setFilled(true);
}

void AbstractCollumn::fullHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFull()->setText(QString::number(hand.getBestResult(Rules::YambField::Full)));
}

void AbstractCollumn::fullUnhovered()
{
    getUIElementFull()->setText("");
}

void AbstractCollumn::fullClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Full);
    getUIElementFull()->setText(QString::number(result));
    getUIElementFull()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementFull()->setFilled(true);
}

void AbstractCollumn::pokerHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementPoker()->setText(QString::number(hand.getBestResult(Rules::YambField::Poker)));
}

void AbstractCollumn::pokerUnhovered()
{
    getUIElementPoker()->setText("");
}

void AbstractCollumn::pokerClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Poker);
    getUIElementPoker()->setText(QString::number(result));
    getUIElementPoker()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementPoker()->setFilled(true);
}

void AbstractCollumn::yambHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementYamb()->setText(QString::number(hand.getBestResult(Rules::YambField::Yamb)));
}

void AbstractCollumn::yambUnhovered()
{
    getUIElementYamb()->setText("");
}

void AbstractCollumn::yambClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Yamb);
    getUIElementYamb()->setText(QString::number(result));
    getUIElementYamb()->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    getUIElementYamb()->setFilled(true);
}
