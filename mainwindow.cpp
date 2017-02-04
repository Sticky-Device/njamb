#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QPixmap>

#include "dicehand.h"
#include "rules.h"

const QString aboutText = "Ovo je verzija njamba razvijana od strane Petra, Stefana i Todorica. Mirko radi sam.";

QPixmap getDicePixMap(int number)
{
    switch (number) {
    case 1:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-1.PNG"));
    case 2:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-2.PNG"));
    case 3:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-3.PNG"));
    case 4:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-4.PNG"));
    case 5:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-5.PNG"));
    case 6:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-6.PNG"));
    default:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-6.PNG"));
    }
}

QPixmap getSelectedDicePixMap(int number)
{
    switch (number) {
    case 1:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-1.PNG"));
    case 2:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-2.PNG"));
    case 3:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-3.PNG"));
    case 4:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-4.PNG"));
    case 5:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-5.PNG"));
    case 6:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-6.PNG"));
    default:
        return QPixmap(QString::fromUtf8(":/dice/resources/dice-selected-6.PNG"));
    }
}

void Dice::drawImage()
{
    uiElement->setPixmap(selected ? getSelectedDicePixMap(val) : getDicePixMap(val));
}

void Dice::setDice(int value)
{
    setValue(value);
    drawImage();
    uiElement->setActive(true);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    downCollumn(ui, engine),
    freeCollumn(ui, engine),
    upCollumn(ui, engine),
    upDownCollumn(ui, engine),
    handCollumn(ui, engine),
    callCollumn(ui, engine)
{
    ui->setupUi(this);

    dice1.setUp(Rules::DEFAULT_DICE, ui->label_dice1);
    dice2.setUp(Rules::DEFAULT_DICE, ui->label_dice2);
    dice3.setUp(Rules::DEFAULT_DICE, ui->label_dice3);
    dice4.setUp(Rules::DEFAULT_DICE, ui->label_dice4);
    dice5.setUp(Rules::DEFAULT_DICE, ui->label_dice5);
    dice6.setUp(Rules::DEFAULT_DICE, ui->label_dice6);

    resetUIElements();

    //events
    connect(ui->diceRollButton, SIGNAL (clicked()), this, SLOT (rollDiceButtonClicked()));
    connect(ui->actionQuit, SIGNAL (triggered()), QApplication::instance(), SLOT (quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadHeavyStuff()
{
}

void MainWindow::rollDiceButtonClicked()
{
    auto savedDice = getSelectedDiceIndices();
    auto hand = engine.rollDice(savedDice);

    dice1.setDice(hand.getDice(1));
    dice2.setDice(hand.getDice(2));
    dice3.setDice(hand.getDice(3));
    dice4.setDice(hand.getDice(4));
    dice5.setDice(hand.getDice(5));
    dice6.setDice(hand.getDice(6));

    downCollumn.diceRolled();
    freeCollumn.diceRolled();
    upCollumn.diceRolled();
    upDownCollumn.diceRolled();
    handCollumn.diceRolled();
    callCollumn.diceRolled();

    if (engine.currentRoll() == 3)
    {
        ui->diceRollButton->setEnabled(false);
    }
}


void MainWindow::on_actionNew_Game_triggered()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Warning, "New game", "Posvadjali smo se?", QMessageBox::Yes|QMessageBox::No).exec())
    {
        engine.resetGame();
        resetUIElements();
        results.reset();
    }
}

void MainWindow::on_actionAbout_Njamb_triggered()
{
    QMessageBox::about(this, "About Njamb", aboutText);
}

void MainWindow::resetUIElements()
{
    dice1.setSelected(false);
    dice2.setSelected(false);
    dice3.setSelected(false);
    dice4.setSelected(false);
    dice5.setSelected(false);
    dice6.setSelected(false);

    // TODO: use dice objects
    ui->label_dice1->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice2->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice3->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice4->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice5->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice6->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));

    downCollumn.reset();
    freeCollumn.reset();
    upCollumn.reset();
    upDownCollumn.reset();
    handCollumn.reset();
    callCollumn.reset();

    ui->diceRollButton->setEnabled(true);

    ui->label_free_numbers_sum->setText("0");
    ui->label_free_minmax_sum->setText("0");
    ui->label_free_major_sum->setText("0");
    ui->label_numbers_sum->setText("0");
    ui->label_minmax_sum->setText("0");
    ui->label_major_sum->setText("0");
    ui->label_final_result->setText("Final Result: 0");
}

std::vector<int> MainWindow::getSelectedDiceIndices()
{
    std::vector<int> result;
    if (dice1.isSelected())
        result.push_back(0);
    if (dice2.isSelected())
        result.push_back(1);
    if (dice3.isSelected())
        result.push_back(2);
    if (dice4.isSelected())
        result.push_back(3);
    if (dice5.isSelected())
        result.push_back(4);
    if (dice6.isSelected())
        result.push_back(5);

    return result;
}


void MainWindow::on_label_dice1_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice1.invertSelection();
}

void MainWindow::on_label_dice2_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice2.invertSelection();
}

void MainWindow::on_label_dice3_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice3.invertSelection();
}

void MainWindow::on_label_dice4_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice4.invertSelection();
}

void MainWindow::on_label_dice5_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice5.invertSelection();
}

void MainWindow::on_label_dice6_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    dice6.invertSelection();
}

void MainWindow::on_label_free_ones_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_free_ones_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Ones);
}

void MainWindow::on_label_free_twos_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Twos);
}

void MainWindow::on_label_free_twos_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Twos);
}

void MainWindow::on_label_free_threes_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Threes);
}

void MainWindow::on_label_free_threes_unhovered()
{
   freeCollumn.fieldUnhovered(Rules::YambField::Threes);
}

void MainWindow::on_label_free_fours_hovered()
{
   freeCollumn.fieldHovered(Rules::YambField::Fours);
}

void MainWindow::on_label_free_fours_unhovered()
{
   freeCollumn.fieldUnhovered(Rules::YambField::Fours);
}

void MainWindow::on_label_free_fives_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Fives);
}

void MainWindow::on_label_free_fives_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Fives);
}

void MainWindow::on_label_free_sixes_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_free_sixes_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_free_max_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Max);
}

void MainWindow::on_label_free_max_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Max);
}

void MainWindow::on_label_free_min_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Min);
}

void MainWindow::on_label_free_min_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Min);
}

void MainWindow::on_label_free_triling_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Triling);
}

void MainWindow::on_label_free_triling_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Triling);
}

void MainWindow::on_label_free_straight_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Straight);
}

void MainWindow::on_label_free_straight_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Straight);
}

void MainWindow::on_label_free_full_hovered()
{
    freeCollumn.fieldHovered(Rules::YambField::Full);
}

void MainWindow::on_label_free_full_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Full);
}

void MainWindow::on_label_free_poker_hovered()
{
   freeCollumn.fieldHovered(Rules::YambField::Poker);
}

void MainWindow::on_label_free_poker_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Poker);
}

void MainWindow::on_label_free_yamb_hovered()
{
   freeCollumn.fieldHovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_free_yamb_unhovered()
{
    freeCollumn.fieldUnhovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_free_ones_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Ones);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Ones);
    updateResults(Rules::Collumn::Free, Rules::YambField::Ones, result);
    nextRound();
}

void MainWindow::on_label_free_twos_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Twos);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Twos);
    updateResults(Rules::Collumn::Free, Rules::YambField::Twos, result);
    nextRound();
}

void MainWindow::on_label_free_threes_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Threes);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Threes);
    updateResults(Rules::Collumn::Free, Rules::YambField::Threes, result);
    nextRound();
}

void MainWindow::on_label_free_fours_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Fours);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fours);
    updateResults(Rules::Collumn::Free, Rules::YambField::Fours, result);
    nextRound();
}

void MainWindow::on_label_free_fives_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Fives);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fives);
    updateResults(Rules::Collumn::Free, Rules::YambField::Fives, result);
    nextRound();
}

void MainWindow::on_label_free_sixes_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Sixes);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Sixes);
    updateResults(Rules::Collumn::Free, Rules::YambField::Sixes, result);
    nextRound();
}

void MainWindow::on_label_free_max_clicked()
{
   freeCollumn.fieldClicked(Rules::YambField::Max);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Max);
    updateResults(Rules::Collumn::Free, Rules::YambField::Max, result);
    nextRound();
}

void MainWindow::on_label_free_min_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Min);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Min);
    updateResults(Rules::Collumn::Free, Rules::YambField::Min, result);
    nextRound();
}

void MainWindow::on_label_free_triling_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Triling);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Triling);
    updateResults(Rules::Collumn::Free, Rules::YambField::Triling, result);
    nextRound();
}

void MainWindow::on_label_free_straight_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Straight);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Straight, engine.currentRoll());
    updateResults(Rules::Collumn::Free, Rules::YambField::Straight, result);
    nextRound();
}

void MainWindow::on_label_free_full_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Full);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Full);
    updateResults(Rules::Collumn::Free, Rules::YambField::Full, result);
    nextRound();
}

void MainWindow::on_label_free_poker_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Poker);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Poker);
    updateResults(Rules::Collumn::Free, Rules::YambField::Poker, result);
    nextRound();
}

void MainWindow::on_label_free_yamb_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Yamb);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Yamb);
    updateResults(Rules::Collumn::Free, Rules::YambField::Yamb, result);
    nextRound();
}

void MainWindow::nextRound()
{
    engine.nextRound();

    dice1.deactivate();
    dice2.deactivate();
    dice3.deactivate();
    dice4.deactivate();
    dice5.deactivate();
    dice6.deactivate();

    downCollumn.nextRound();
    freeCollumn.nextRound();
    upCollumn.nextRound();
    upDownCollumn.nextRound();
    handCollumn.nextRound();
    callCollumn.nextRound();

    ui->diceRollButton->setEnabled(true);

    // lock/unlock appropriate fields
}

void MainWindow::updateResults(Rules::Collumn collumn, Rules::YambField field, int value)
{
    results.updateResult(collumn, field, value);

    ui->label_free_numbers_sum->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::Numbers)));
    ui->label_free_minmax_sum->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::MinMax)));
    ui->label_free_major_sum->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::Major)));
    ui->label_numbers_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::Numbers)));
    ui->label_minmax_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::MinMax)));
    ui->label_major_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::Major)));

    ui->label_final_result->setText(QString("Final Result: ") + QString::number(results.getFinalResult()));
}


void MainWindow::on_label_down_ones_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Ones);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Ones);
    updateResults(Rules::Collumn::Down, Rules::YambField::Ones, result);
    nextRound();
}

void MainWindow::on_label_down_ones_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_down_ones_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Ones);
}

void MainWindow::on_label_down_twos_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Twos);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Twos);
    updateResults(Rules::Collumn::Down, Rules::YambField::Twos, result);
    nextRound();
}

void MainWindow::on_label_down_twos_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Twos);
}

void MainWindow::on_label_down_twos_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Twos);
}

void MainWindow::on_label_down_threes_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Threes);
}

void MainWindow::on_label_up_yamb_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Yamb);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Yamb);
    updateResults(Rules::Collumn::Down, Rules::YambField::Yamb, result);
    nextRound();
}

void MainWindow::on_label_up_yamb_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_up_yamb_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_up_poker_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Poker);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Poker);
    updateResults(Rules::Collumn::Down, Rules::YambField::Poker, result);
    nextRound();
}

void MainWindow::on_label_up_poker_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Poker);
}

void MainWindow::on_label_up_poker_unhovered()
{
   upCollumn.fieldUnhovered(Rules::YambField::Poker);
}

void MainWindow::on_label_up_full_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Full);
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Full);
    updateResults(Rules::Collumn::Down, Rules::YambField::Full, result);
    nextRound();
}

void MainWindow::on_label_up_full_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Full);
}

void MainWindow::on_label_up_full_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Full);
}

void MainWindow::on_label_updown_max_clicked()
{
    upDownCollumn.fieldClicked(Rules::YambField::Max);
}

void MainWindow::on_label_updown_max_hovered()
{
    upDownCollumn.fieldHovered(Rules::YambField::Max);
}

void MainWindow::on_label_updown_max_unhovered()
{
    upDownCollumn.fieldUnhovered(Rules::YambField::Max);
}

void MainWindow::on_label_updown_min_clicked()
{
    upDownCollumn.fieldClicked(Rules::YambField::Min);
}

void MainWindow::on_label_updown_min_hovered()
{
    upDownCollumn.fieldHovered(Rules::YambField::Min);
}

void MainWindow::on_label_updown_min_unhovered()
{
    upDownCollumn.fieldUnhovered(Rules::YambField::Min);
}

void MainWindow::on_label_updown_triling_clicked()
{
    upDownCollumn.fieldClicked(Rules::YambField::Triling);
}

void MainWindow::on_label_updown_triling_hovered()
{
    upDownCollumn.fieldHovered(Rules::YambField::Triling);
}

void MainWindow::on_label_updown_triling_unhovered()
{
    upDownCollumn.fieldUnhovered(Rules::YambField::Triling);
}

void MainWindow::on_label_updown_sixes_clicked()
{
    upDownCollumn.fieldClicked(Rules::YambField::Sixes);
}

void MainWindow::on_label_updown_sixes_hovered()
{
    upDownCollumn.fieldHovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_updown_sixes_unhovered()
{
    upDownCollumn.fieldUnhovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_hand_ones_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Ones);
}

void MainWindow::on_label_hand_ones_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_hand_ones_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Ones);
}

void MainWindow::on_label_call_ones_clicked()
{
    callCollumn.fieldClicked(Rules::YambField::Ones);
}

void MainWindow::on_label_call_ones_hovered()
{
    callCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_call_ones_unhovered()
{
    callCollumn.fieldUnhovered(Rules::YambField::Ones);
}
