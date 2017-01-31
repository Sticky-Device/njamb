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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dice1.setUp(Rules::DEFAULT_DICE, ui->label_dice1);
    dice2.setUp(Rules::DEFAULT_DICE, ui->label_dice2);
    dice3.setUp(Rules::DEFAULT_DICE, ui->label_dice3);
    dice4.setUp(Rules::DEFAULT_DICE, ui->label_dice4);
    dice5.setUp(Rules::DEFAULT_DICE, ui->label_dice5);
    dice6.setUp(Rules::DEFAULT_DICE, ui->label_dice6);

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

    ui->label_free_ones->setActive(true);
    ui->label_free_twos->setActive(true);
    ui->label_free_threes->setActive(true);
    ui->label_free_fours->setActive(true);
    ui->label_free_fives->setActive(true);
    ui->label_free_sixes->setActive(true);
    ui->label_free_max->setActive(true);
    ui->label_free_min->setActive(true);
    ui->label_free_triling->setActive(true);
    ui->label_free_straight->setActive(true);
    ui->label_free_full->setActive(true);
    ui->label_free_poker->setActive(true);
    ui->label_free_yamb->setActive(true);

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

    ui->label_dice1->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice2->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice3->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice4->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice5->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));
    ui->label_dice6->setPixmap(getDicePixMap(Rules::DEFAULT_DICE));

    ui->label_free_ones->setText("");
    ui->label_free_ones->setActive(false);
    ui->label_free_twos->setText("");
    ui->label_free_twos->setActive(false);
    ui->label_free_threes->setText("");
    ui->label_free_threes->setActive(false);
    ui->label_free_fours->setText("");
    ui->label_free_fours->setActive(false);
    ui->label_free_fives->setText("");
    ui->label_free_fives->setActive(false);
    ui->label_free_sixes->setText("");
    ui->label_free_sixes->setActive(false);
    ui->label_free_max->setText("");
    ui->label_free_max->setActive(false);
    ui->label_free_min->setText("");
    ui->label_free_min->setActive(false);
    ui->label_free_triling->setText("");
    ui->label_free_triling->setActive(false);
    ui->label_free_straight->setText("");
    ui->label_free_straight->setActive(false);
    ui->label_free_full->setText("");
    ui->label_free_full->setActive(false);
    ui->label_free_poker->setText("");
    ui->label_free_poker->setActive(false);
    ui->label_free_yamb->setText("");
    ui->label_free_yamb->setActive(false);

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
    auto hand = engine.getCurrentHand();
    ui->label_free_ones->setText(QString::number(hand.getBestResult(Rules::YambField::Ones)));
}

void MainWindow::on_label_free_ones_unhovered()
{
    ui->label_free_ones->setText("");
}

void MainWindow::on_label_free_twos_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_twos->setText(QString::number(hand.getBestResult(Rules::YambField::Twos)));
}

void MainWindow::on_label_free_twos_unhovered()
{
    ui->label_free_twos->setText("");
}

void MainWindow::on_label_free_threes_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_threes->setText(QString::number(hand.getBestResult(Rules::YambField::Threes)));
}

void MainWindow::on_label_free_threes_unhovered()
{
    ui->label_free_threes->setText("");
}

void MainWindow::on_label_free_fours_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_fours->setText(QString::number(hand.getBestResult(Rules::YambField::Fours)));
}

void MainWindow::on_label_free_fours_unhovered()
{
    ui->label_free_fours->setText("");
}

void MainWindow::on_label_free_fives_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_fives->setText(QString::number(hand.getBestResult(Rules::YambField::Fives)));
}

void MainWindow::on_label_free_fives_unhovered()
{
    ui->label_free_fives->setText("");
}

void MainWindow::on_label_free_sixes_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_sixes->setText(QString::number(hand.getBestResult(Rules::YambField::Sixes)));
}

void MainWindow::on_label_free_sixes_unhovered()
{
    ui->label_free_sixes->setText("");
}

void MainWindow::on_label_free_max_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_max->setText(QString::number(hand.getBestResult(Rules::YambField::Max)));
}

void MainWindow::on_label_free_max_unhovered()
{
    ui->label_free_max->setText("");
}

void MainWindow::on_label_free_min_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_min->setText(QString::number(hand.getBestResult(Rules::YambField::Min)));
}

void MainWindow::on_label_free_min_unhovered()
{
    ui->label_free_min->setText("");
}

void MainWindow::on_label_free_triling_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_triling->setText(QString::number(hand.getBestResult(Rules::YambField::Triling)));
}

void MainWindow::on_label_free_triling_unhovered()
{
    ui->label_free_triling->setText("");
}

void MainWindow::on_label_free_straight_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_straight->setText(QString::number(hand.getBestResult(Rules::YambField::Straight)));
}

void MainWindow::on_label_free_straight_unhovered()
{
    ui->label_free_straight->setText("");
}

void MainWindow::on_label_free_full_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_full->setText(QString::number(hand.getBestResult(Rules::YambField::Full)));
}

void MainWindow::on_label_free_full_unhovered()
{
    ui->label_free_full->setText("");
}

void MainWindow::on_label_free_poker_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_poker->setText(QString::number(hand.getBestResult(Rules::YambField::Poker)));
}

void MainWindow::on_label_free_poker_unhovered()
{
    ui->label_free_poker->setText("");
}

void MainWindow::on_label_free_yamb_hovered()
{
    auto hand = engine.getCurrentHand();
    ui->label_free_yamb->setText(QString::number(hand.getBestResult(Rules::YambField::Yamb)));
}

void MainWindow::on_label_free_yamb_unhovered()
{
    ui->label_free_yamb->setText("");
}

void MainWindow::on_label_free_ones_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Ones);
    ui->label_free_ones->setText(QString::number(result));
    ui->label_free_ones->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Ones, result);
    nextRound();
}

void MainWindow::on_label_free_twos_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Twos);
    ui->label_free_twos->setText(QString::number(hand.getBestResult(Rules::YambField::Twos)));
    ui->label_free_twos->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Twos, result);
    nextRound();
}

void MainWindow::on_label_free_threes_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Threes);
    ui->label_free_threes->setText(QString::number(hand.getBestResult(Rules::YambField::Threes)));
    ui->label_free_threes->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Threes, result);
    nextRound();
}

void MainWindow::on_label_free_fours_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fours);
    ui->label_free_fours->setText(QString::number(hand.getBestResult(Rules::YambField::Fours)));
    ui->label_free_fours->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Fours, result);
    nextRound();
}

void MainWindow::on_label_free_fives_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Fives);
    ui->label_free_fives->setText(QString::number(hand.getBestResult(Rules::YambField::Fives)));
    ui->label_free_fives->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Fives, result);
    nextRound();
}

void MainWindow::on_label_free_sixes_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Sixes);
    ui->label_free_sixes->setText(QString::number(hand.getBestResult(Rules::YambField::Sixes)));
    ui->label_free_sixes->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Sixes, result);
    nextRound();
}

void MainWindow::on_label_free_max_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Max);
    ui->label_free_max->setText(QString::number(hand.getBestResult(Rules::YambField::Max)));
    ui->label_free_max->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Max, result);
    nextRound();
}

void MainWindow::on_label_free_min_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Min);
    ui->label_free_min->setText(QString::number(hand.getBestResult(Rules::YambField::Min)));
    ui->label_free_min->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Min, result);
    nextRound();
}

void MainWindow::on_label_free_triling_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Triling);
    ui->label_free_triling->setText(QString::number(hand.getBestResult(Rules::YambField::Triling)));
    ui->label_free_triling->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Triling, result);
    nextRound();
}

void MainWindow::on_label_free_straight_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Straight);
    ui->label_free_straight->setText(QString::number(hand.getBestResult(Rules::YambField::Straight)));
    ui->label_free_straight->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Straight, result);
    nextRound();
}

void MainWindow::on_label_free_full_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Full);
    ui->label_free_full->setText(QString::number(hand.getBestResult(Rules::YambField::Full)));
    ui->label_free_full->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Full, result);
    nextRound();
}

void MainWindow::on_label_free_poker_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Poker);
    ui->label_free_poker->setText(QString::number(hand.getBestResult(Rules::YambField::Poker)));
    ui->label_free_poker->setFilled();
    updateResults(Rules::Collumn::Free, Rules::YambField::Poker, result);
    nextRound();
}

void MainWindow::on_label_free_yamb_clicked()
{
    auto hand = engine.getCurrentHand();
    auto result = hand.getBestResult(Rules::YambField::Yamb);
    ui->label_free_yamb->setText(QString::number(hand.getBestResult(Rules::YambField::Yamb)));
    ui->label_free_yamb->setFilled();
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

    ui->label_free_ones->setActive(false);
    ui->label_free_twos->setActive(false);
    ui->label_free_threes->setActive(false);
    ui->label_free_fours->setActive(false);
    ui->label_free_fives->setActive(false);
    ui->label_free_sixes->setActive(false);
    ui->label_free_max->setActive(false);
    ui->label_free_min->setActive(false);
    ui->label_free_triling->setActive(false);
    ui->label_free_straight->setActive(false);
    ui->label_free_full->setActive(false);
    ui->label_free_poker->setActive(false);
    ui->label_free_yamb->setActive(false);

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
