#include "abstractcollumn.h"
#include "rules.h"

AbstractCollumn::AbstractCollumn(Ui::MainWindow *ui, NjambEngine & eng) : ui(ui), engine(eng)
{

}

void AbstractCollumn::reset()
{
    getUIElementOnes()->setText("");
    getUIElementOnes()->setActive(false);
    getUIElementOnes()->setFilled(false);
    getUIElementOnes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementTwos()->setText("");
    getUIElementTwos()->setActive(false);
    getUIElementTwos()->setFilled(false);
    getUIElementTwos()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementThrees()->setText("");
    getUIElementThrees()->setActive(false);
    getUIElementThrees()->setFilled(false);
    getUIElementThrees()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFours()->setText("");
    getUIElementFours()->setActive(false);
    getUIElementFours()->setFilled(false);
    getUIElementFours()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFives()->setText("");
    getUIElementFives()->setActive(false);
    getUIElementFives()->setFilled(false);
    getUIElementFives()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementSixes()->setText("");
    getUIElementSixes()->setActive(false);
    getUIElementSixes()->setFilled(false);
    getUIElementSixes()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementMax()->setText("");
    getUIElementMax()->setActive(false);
    getUIElementMax()->setFilled(false);
    getUIElementMax()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementMin()->setText("");
    getUIElementMin()->setActive(false);
    getUIElementMin()->setFilled(false);
    getUIElementMin()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementTriling()->setText("");
    getUIElementTriling()->setActive(false);
    getUIElementTriling()->setFilled(false);
    getUIElementTriling()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementStraight()->setText("");
    getUIElementStraight()->setActive(false);
    getUIElementStraight()->setFilled(false);
    getUIElementStraight()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementFull()->setText("");
    getUIElementFull()->setActive(false);
    getUIElementFull()->setFilled(false);
    getUIElementFull()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementPoker()->setText("");
    getUIElementPoker()->setActive(false);
    getUIElementPoker()->setFilled(false);
    getUIElementPoker()->setStyleSheet(Rules::FREE_LABEL_COLOR);
    getUIElementYamb()->setText("");
    getUIElementYamb()->setActive(false);
    getUIElementYamb()->setFilled(false);
    getUIElementYamb()->setStyleSheet(Rules::FREE_LABEL_COLOR);
}

void AbstractCollumn::onesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementOnes()->setText(QString::number(hand.getBestResult(Rules::YambField::Ones)));
}

void AbstractCollumn::onesUnhovered()
{
    ui->label_free_ones->setText("");
}

void AbstractCollumn::onesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Ones);
    ui->label_free_ones->setText(QString::number(result));
    ui->label_free_ones->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_ones->setFilled(true);
}

void AbstractCollumn::twosHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementTwos()->setText(QString::number(hand.getBestResult(Rules::YambField::Twos)));
}

void AbstractCollumn::twosUnhovered()
{
    ui->label_free_twos->setText("");
}

void AbstractCollumn::twosClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Twos);
    ui->label_free_twos->setText(QString::number(result));
    ui->label_free_twos->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_twos->setFilled(true);
}

void AbstractCollumn::threesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementThrees()->setText(QString::number(hand.getBestResult(Rules::YambField::Threes)));
}

void AbstractCollumn::threesUnhovered()
{
    ui->label_free_threes->setText("");
}

void AbstractCollumn::threesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Threes);
    ui->label_free_threes->setText(QString::number(result));
    ui->label_free_threes->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_threes->setFilled(true);
}

void AbstractCollumn::foursHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFours()->setText(QString::number(hand.getBestResult(Rules::YambField::Fours)));
}

void AbstractCollumn::foursUnhovered()
{
    ui->label_free_fours->setText("");
}

void AbstractCollumn::foursClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fours);
    ui->label_free_fours->setText(QString::number(result));
    ui->label_free_fours->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_fours->setFilled(true);
}

void AbstractCollumn::fivesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFives()->setText(QString::number(hand.getBestResult(Rules::YambField::Fives)));
}

void AbstractCollumn::fivesUnhovered()
{
    ui->label_free_fives->setText("");
}

void AbstractCollumn::fivesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fives);
    ui->label_free_fives->setText(QString::number(result));
    ui->label_free_fives->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_fives->setFilled(true);
}

void AbstractCollumn::sixesHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementSixes()->setText(QString::number(hand.getBestResult(Rules::YambField::Sixes)));
}

void AbstractCollumn::sixesUnhovered()
{
    ui->label_free_sixes->setText("");
}

void AbstractCollumn::sixesClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Sixes);
    ui->label_free_sixes->setText(QString::number(result));
    ui->label_free_sixes->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_sixes->setFilled(true);
}

void AbstractCollumn::maxHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementMax()->setText(QString::number(hand.getBestResult(Rules::YambField::Max)));
}

void AbstractCollumn::maxUnhovered()
{
    ui->label_free_max->setText("");
}

void AbstractCollumn::maxClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Max);
    ui->label_free_max->setText(QString::number(result));
    ui->label_free_max->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_max->setFilled(true);
}

void AbstractCollumn::minHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementMin()->setText(QString::number(hand.getBestResult(Rules::YambField::Min)));
}

void AbstractCollumn::minUnhovered()
{
    ui->label_free_min->setText("");
}

void AbstractCollumn::minClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Min);
    ui->label_free_min->setText(QString::number(result));
    ui->label_free_min->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_min->setFilled(true);
}

void AbstractCollumn::trilingHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementTriling()->setText(QString::number(hand.getBestResult(Rules::YambField::Triling)));
}

void AbstractCollumn::trilingUnhovered()
{
    ui->label_free_triling->setText("");
}

void AbstractCollumn::trilingClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Triling);
    ui->label_free_triling->setText(QString::number(result));
    ui->label_free_triling->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_triling->setFilled(true);
}

void AbstractCollumn::straightHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementStraight()->setText(QString::number(hand.getBestResult(Rules::YambField::Straight)));
}

void AbstractCollumn::straightUnhovered()
{
    ui->label_free_straight->setText("");
}

void AbstractCollumn::straightClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Straight);
    ui->label_free_straight->setText(QString::number(result));
    ui->label_free_straight->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_straight->setFilled(true);
}

void AbstractCollumn::fullHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementFull()->setText(QString::number(hand.getBestResult(Rules::YambField::Full)));
}

void AbstractCollumn::fullUnhovered()
{
    ui->label_free_full->setText("");
}

void AbstractCollumn::fullClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Full);
    ui->label_free_full->setText(QString::number(result));
    ui->label_free_full->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_full->setFilled(true);
}

void AbstractCollumn::pokerHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementPoker()->setText(QString::number(hand.getBestResult(Rules::YambField::Poker)));
}

void AbstractCollumn::pokerUnhovered()
{
    ui->label_free_poker->setText("");
}

void AbstractCollumn::pokerClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Poker);
    ui->label_free_poker->setText(QString::number(result));
    ui->label_free_poker->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_poker->setFilled(true);
}

void AbstractCollumn::yambHovered()
{
    auto hand = engine.getCurrentHand();
    getUIElementYamb()->setText(QString::number(hand.getBestResult(Rules::YambField::Yamb)));
}

void AbstractCollumn::yambUnhovered()
{
    ui->label_free_yamb->setText("");
}

void AbstractCollumn::yambClicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Yamb);
    ui->label_free_yamb->setText(QString::number(result));
    ui->label_free_yamb->setStyleSheet(Rules::FILLED_LABEL_COLOR);
    ui->label_free_yamb->setFilled(true);
}
