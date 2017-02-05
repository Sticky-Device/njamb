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
    downCollumn(ui, engine, results),
    freeCollumn(ui, engine, results),
    upCollumn(ui, engine, results),
    upDownCollumn(ui, engine, results),
    handCollumn(ui, engine, results),
    callCollumn(ui, engine, results)
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

    getNumbersSumElementForCollumn(Rules::Collumn::Down)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::Down)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::Down)->setText("0");
    getNumbersSumElementForCollumn(Rules::Collumn::Free)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::Free)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::Free)->setText("0");
    getNumbersSumElementForCollumn(Rules::Collumn::Up)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::Up)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::Up)->setText("0");
    getNumbersSumElementForCollumn(Rules::Collumn::UpDown)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::UpDown)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::UpDown)->setText("0");
    getNumbersSumElementForCollumn(Rules::Collumn::Hand)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::Hand)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::Hand)->setText("0");
    getNumbersSumElementForCollumn(Rules::Collumn::Call)->setText("0");
    getMinMaxSumElementForCollumn(Rules::Collumn::Call)->setText("0");
    getMajorSumElementForCollumn(Rules::Collumn::Call)->setText("0");
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

QLabel *MainWindow::getNumbersSumElementForCollumn(Rules::Collumn collumn)
{
    switch (collumn) {
    case Rules::Collumn::Down :
        return ui->label_down_numbers_sum;
    case Rules::Collumn::Free :
        return ui->label_free_numbers_sum;
    case Rules::Collumn::Up :
        return ui->label_up_numbers_sum;
    case Rules::Collumn::UpDown :
        return ui->label_updown_numbers_sum;
    case Rules::Collumn::Hand :
        return ui->label_hand_numbers_sum;
    case Rules::Collumn::Call :
        return ui->label_call_numbers_sum;
        break;
    default:
        break;
    }

    return ui->label_down_numbers_sum;
}

QLabel *MainWindow::getMinMaxSumElementForCollumn(Rules::Collumn collumn)
{
    switch (collumn) {
    case Rules::Collumn::Down :
        return ui->label_down_minmax_sum;
    case Rules::Collumn::Free :
        return ui->label_free_minmax_sum;
    case Rules::Collumn::Up :
        return ui->label_up_minmax_sum;
    case Rules::Collumn::UpDown :
        return ui->label_updown_minmax_sum;
    case Rules::Collumn::Hand :
        return ui->label_hand_minmax_sum;
    case Rules::Collumn::Call :
        return ui->label_call_minmax_sum;
        break;
    default:
        break;
    }

    return ui->label_down_minmax_sum;
}

QLabel *MainWindow::getMajorSumElementForCollumn(Rules::Collumn collumn)
{
    switch (collumn) {
    case Rules::Collumn::Down :
        return ui->label_down_major_sum;
    case Rules::Collumn::Free :
        return ui->label_free_major_sum;
    case Rules::Collumn::Up :
        return ui->label_up_major_sum;
    case Rules::Collumn::UpDown :
        return ui->label_updown_major_sum;
    case Rules::Collumn::Hand :
        return ui->label_hand_major_sum;
    case Rules::Collumn::Call :
        return ui->label_call_major_sum;
        break;
    default:
        break;
    }

    // TODO: assert
    // probably should add some hidden label for these kind of things
    return ui->label_down_major_sum;
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
}

void MainWindow::updateResultsForCollumn(Rules::Collumn collumn)
{
    getNumbersSumElementForCollumn(collumn)->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::Numbers)));
    getMinMaxSumElementForCollumn(collumn)->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::MinMax)));
    getMajorSumElementForCollumn(collumn)->setText(QString::number(results.getResult(collumn, Rules::CollumnGroup::Major)));
}

void MainWindow::updateResults()
{
    updateResultsForCollumn(Rules::Collumn::Down);
    updateResultsForCollumn(Rules::Collumn::Free);
    updateResultsForCollumn(Rules::Collumn::Up);
    updateResultsForCollumn(Rules::Collumn::UpDown);
    updateResultsForCollumn(Rules::Collumn::Hand);
    updateResultsForCollumn(Rules::Collumn::Call);
    ui->label_numbers_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::Numbers)));
    ui->label_minmax_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::MinMax)));
    ui->label_major_sum->setText(QString::number(results.getResult(Rules::CollumnGroup::Major)));

    ui->label_final_result->setText(QString("Final Result: ") + QString::number(results.getFinalResult()));
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

/***** FREE COLLUMN SLOTS *****/
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
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_twos_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Twos);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_threes_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Threes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_fours_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Fours);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_fives_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Fives);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_sixes_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Sixes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_max_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Max);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_min_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Min);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_triling_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Triling);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_straight_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Straight);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_full_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Full);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_poker_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Poker);
    updateResults();
    nextRound();
}

void MainWindow::on_label_free_yamb_clicked()
{
    freeCollumn.fieldClicked(Rules::YambField::Yamb);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_ones_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Ones);
    updateResults();
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
    updateResults();
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
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_threes_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Threes);
}

void MainWindow::on_label_down_threes_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Threes);
}

void MainWindow::on_label_down_fours_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Fours);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_fours_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Fours);
}

void MainWindow::on_label_down_fours_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Fours);
}

void MainWindow::on_label_down_fives_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Fives);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_fives_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Fives);
}

void MainWindow::on_label_down_fives_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Fives);
}

void MainWindow::on_label_down_sixes_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Sixes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_sixes_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_down_sixes_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_down_max_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Max);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_max_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Max);
}

void MainWindow::on_label_down_max_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Max);
}

void MainWindow::on_label_down_min_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Min);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_min_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Min);
}

void MainWindow::on_label_down_min_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Min);
}

void MainWindow::on_label_down_triling_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Triling);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_triling_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Triling);
}

void MainWindow::on_label_down_triling_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Triling);
}

void MainWindow::on_label_down_straight_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Straight);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_straight_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Straight);
}

void MainWindow::on_label_down_straight_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Straight);
}

void MainWindow::on_label_down_full_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Full);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_full_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Full);
}

void MainWindow::on_label_down_full_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Full);
}

void MainWindow::on_label_down_poker_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Poker);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_poker_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Poker);
}

void MainWindow::on_label_down_poker_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Poker);
}

void MainWindow::on_label_down_yamb_clicked()
{
    downCollumn.fieldClicked(Rules::YambField::Yamb);
    updateResults();
    nextRound();
}

void MainWindow::on_label_down_yamb_hovered()
{
    downCollumn.fieldHovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_down_yamb_unhovered()
{
    downCollumn.fieldUnhovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_up_ones_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Ones);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_ones_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_up_ones_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Ones);
}

void MainWindow::on_label_up_twos_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Twos);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_twos_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Twos);
}

void MainWindow::on_label_up_twos_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Twos);
}

void MainWindow::on_label_up_threes_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Threes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_threes_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Threes);
}

void MainWindow::on_label_up_threes_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Threes);
}

void MainWindow::on_label_up_fours_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Fours);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_fours_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Fours);
}

void MainWindow::on_label_up_fours_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Fours);
}

void MainWindow::on_label_up_fives_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Fives);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_fives_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Fives);
}

void MainWindow::on_label_up_fives_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Fives);
}

void MainWindow::on_label_up_sixes_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Sixes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_sixes_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_up_sixes_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_up_max_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Max);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_max_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Max);
}

void MainWindow::on_label_up_max_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Max);
}

void MainWindow::on_label_up_min_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Min);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_min_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Min);
}

void MainWindow::on_label_up_min_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Min);
}

void MainWindow::on_label_up_triling_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Triling);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_triling_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Triling);
}

void MainWindow::on_label_up_triling_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Triling);
}

void MainWindow::on_label_up_straight_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Straight);
    updateResults();
    nextRound();
}

void MainWindow::on_label_up_straight_hovered()
{
    upCollumn.fieldHovered(Rules::YambField::Straight);
}

void MainWindow::on_label_up_straight_unhovered()
{
    upCollumn.fieldUnhovered(Rules::YambField::Straight);
}

void MainWindow::on_label_up_full_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Full);
    updateResults();
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

void MainWindow::on_label_up_poker_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Poker);
    updateResults();
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

void MainWindow::on_label_up_yamb_clicked()
{
    upCollumn.fieldClicked(Rules::YambField::Yamb);
    updateResults();
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

void MainWindow::on_label_updown_ones_clicked()
{

}

void MainWindow::on_label_updown_ones_hovered()
{

}

void MainWindow::on_label_updown_ones_unhovered()
{

}

void MainWindow::on_label_updown_twos_clicked()
{

}

void MainWindow::on_label_updown_twos_hovered()
{

}

void MainWindow::on_label_updown_twos_unhovered()
{

}

void MainWindow::on_label_updown_threes_clicked()
{

}

void MainWindow::on_label_updown_threes_hovered()
{

}

void MainWindow::on_label_updown_threes_unhovered()
{

}

void MainWindow::on_label_updown_fours_clicked()
{

}

void MainWindow::on_label_updown_fours_hovered()
{

}

void MainWindow::on_label_updown_fours_unhovered()
{

}

void MainWindow::on_label_updown_fives_clicked()
{

}

void MainWindow::on_label_updown_fives_hovered()
{

}

void MainWindow::on_label_updown_fives_unhovered()
{

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

void MainWindow::on_label_updown_straight_clicked()
{

}

void MainWindow::on_label_updown_straight_hovered()
{

}

void MainWindow::on_label_updown_straight_unhovered()
{

}

void MainWindow::on_label_updown_full_clicked()
{

}

void MainWindow::on_label_updown_full_hovered()
{

}

void MainWindow::on_label_updown_full_unhovered()
{

}

void MainWindow::on_label_updown_poker_clicked()
{

}

void MainWindow::on_label_updown_poker_hovered()
{

}

void MainWindow::on_label_updown_poker_unhovered()
{

}

void MainWindow::on_label_updown_yamb_clicked()
{

}

void MainWindow::on_label_updown_yamb_hovered()
{

}

void MainWindow::on_label_updown_yamb_unhovered()
{

}

void MainWindow::on_label_hand_ones_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Ones);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_ones_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Ones);
}

void MainWindow::on_label_hand_ones_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Ones);
}

void MainWindow::on_label_hand_twos_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Twos);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_twos_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Twos);
}

void MainWindow::on_label_hand_twos_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Twos);
}

void MainWindow::on_label_hand_threes_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Threes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_threes_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Threes);
}

void MainWindow::on_label_hand_threes_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Threes);
}

void MainWindow::on_label_hand_fours_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Fours);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_fours_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Fours);
}

void MainWindow::on_label_hand_fours_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Fours);
}

void MainWindow::on_label_hand_fives_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Fives);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_fives_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Fives);
}

void MainWindow::on_label_hand_fives_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Fives);
}

void MainWindow::on_label_hand_sixes_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Sixes);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_sixes_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_hand_sixes_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Sixes);
}

void MainWindow::on_label_hand_max_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Max);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_max_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Max);
}

void MainWindow::on_label_hand_max_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Max);
}

void MainWindow::on_label_hand_min_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Min);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_min_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Min);
}

void MainWindow::on_label_hand_min_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Min);
}

void MainWindow::on_label_hand_triling_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Triling);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_triling_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Triling);
}

void MainWindow::on_label_hand_triling_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Triling);
}

void MainWindow::on_label_hand_straight_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Straight);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_straight_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Straight);
}

void MainWindow::on_label_hand_straight_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Straight);
}

void MainWindow::on_label_hand_full_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Full);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_full_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Full);
}

void MainWindow::on_label_hand_full_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Full);
}

void MainWindow::on_label_hand_poker_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Poker);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_poker_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Poker);
}

void MainWindow::on_label_hand_poker_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Poker);
}

void MainWindow::on_label_hand_yamb_clicked()
{
    handCollumn.fieldClicked(Rules::YambField::Yamb);
    updateResults();
    nextRound();
}

void MainWindow::on_label_hand_yamb_hovered()
{
    handCollumn.fieldHovered(Rules::YambField::Yamb);
}

void MainWindow::on_label_hand_yamb_unhovered()
{
    handCollumn.fieldUnhovered(Rules::YambField::Yamb);
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

void MainWindow::on_label_call_twos_clicked()
{

}

void MainWindow::on_label_call_twos_hovered()
{

}

void MainWindow::on_label_call_twos_unhovered()
{

}

void MainWindow::on_label_call_threes_clicked()
{

}

void MainWindow::on_label_call_threes_hovered()
{

}

void MainWindow::on_label_call_threes_unhovered()
{

}

void MainWindow::on_label_call_fours_clicked()
{

}

void MainWindow::on_label_call_fours_hovered()
{

}

void MainWindow::on_label_call_fours_unhovered()
{

}

void MainWindow::on_label_call_fives_clicked()
{

}

void MainWindow::on_label_call_fives_hovered()
{

}

void MainWindow::on_label_call_fives_unhovered()
{

}

void MainWindow::on_label_call_sixes_clicked()
{

}

void MainWindow::on_label_call_sixes_hovered()
{

}

void MainWindow::on_label_call_sixes_unhovered()
{

}

void MainWindow::on_label_call_max_clicked()
{

}

void MainWindow::on_label_call_max_hovered()
{

}

void MainWindow::on_label_call_max_unhovered()
{

}

void MainWindow::on_label_call_min_clicked()
{

}

void MainWindow::on_label_call_min_hovered()
{

}

void MainWindow::on_label_call_min_unhovered()
{

}

void MainWindow::on_label_call_triling_clicked()
{

}

void MainWindow::on_label_call_triling_hovered()
{

}

void MainWindow::on_label_call_triling_unhovered()
{

}

void MainWindow::on_label_call_straight_clicked()
{

}

void MainWindow::on_label_call_straight_hovered()
{

}

void MainWindow::on_label_call_straight_unhovered()
{

}

void MainWindow::on_label_call_full_clicked()
{

}

void MainWindow::on_label_call_full_hovered()
{

}

void MainWindow::on_label_call_full_unhovered()
{

}

void MainWindow::on_label_call_poker_clicked()
{

}

void MainWindow::on_label_call_poker_hovered()
{

}

void MainWindow::on_label_call_poker_unhovered()
{

}

void MainWindow::on_label_call_yamb_clicked()
{

}

void MainWindow::on_label_call_yamb_hovered()
{

}

void MainWindow::on_label_call_yamb_unhovered()
{

}
