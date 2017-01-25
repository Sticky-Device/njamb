#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QPixmap>

#include "dicehand.h"

const QString aboutText = "Ovo je verzija njamba razvijana od strane Petra, Stefana i Todorica. Mirko radi sam.";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //events
    connect(ui->diceRollButton, SIGNAL (clicked()), this, SLOT (rollDiceButtonClicked()));
    connect(ui->actionQuit, SIGNAL (triggered()), QApplication::instance(), SLOT (quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::rollDiceButtonClicked()
{
    auto hand = engine.rollDice();

    ui->label_dice1->setPixmap(getDicePixMap(hand.getDice(1)));
    ui->label_dice2->setPixmap(getDicePixMap(hand.getDice(2)));
    ui->label_dice3->setPixmap(getDicePixMap(hand.getDice(3)));
    ui->label_dice4->setPixmap(getDicePixMap(hand.getDice(4)));
    ui->label_dice5->setPixmap(getDicePixMap(hand.getDice(5)));
    ui->label_dice6->setPixmap(getDicePixMap(hand.getDice(6)));

    ui->label_free_ones->setText(QString::number(hand.getBestResult(DiceHandResult::Ones)));
    ui->label_free_twos->setText(QString::number(hand.getBestResult(DiceHandResult::Twos)));
    ui->label_free_threes->setText(QString::number(hand.getBestResult(DiceHandResult::Threes)));
    ui->label_free_fours->setText(QString::number(hand.getBestResult(DiceHandResult::Fours)));
    ui->label_free_fives->setText(QString::number(hand.getBestResult(DiceHandResult::Fives)));
    ui->label_free_sixes->setText(QString::number(hand.getBestResult(DiceHandResult::Sixes)));
}


void MainWindow::on_actionNew_Game_triggered()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Warning, "New game", "Posvadjali smo se?", QMessageBox::Yes|QMessageBox::No).exec())
    {
        engine.resetGame();
        resetUIElements();
    }
}

void MainWindow::on_actionAbout_Njamb_triggered()
{
    QMessageBox::about(this, "About Njamb", aboutText);
}

void MainWindow::resetUIElements()
{
    ui->label_dice1->setPixmap(getDicePixMap(6));
    ui->label_dice2->setPixmap(getDicePixMap(6));
    ui->label_dice3->setPixmap(getDicePixMap(6));
    ui->label_dice4->setPixmap(getDicePixMap(6));
    ui->label_dice5->setPixmap(getDicePixMap(6));
    ui->label_dice6->setPixmap(getDicePixMap(6));

    ui->label_free_ones->setText("0");
    ui->label_free_twos->setText("0");
    ui->label_free_threes->setText("0");
    ui->label_free_fours->setText("0");
    ui->label_free_fives->setText("0");
    ui->label_free_sixes->setText("0");
}


void MainWindow::on_label_dice1_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice1->setPixmap(getSelectedDicePixMap(hand.getDice(1)));
}

void MainWindow::on_label_dice2_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice2->setPixmap(getSelectedDicePixMap(hand.getDice(2)));
}

void MainWindow::on_label_dice3_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice3->setPixmap(getSelectedDicePixMap(hand.getDice(3)));
}

void MainWindow::on_label_dice4_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice4->setPixmap(getSelectedDicePixMap(hand.getDice(4)));
}

void MainWindow::on_label_dice5_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice5->setPixmap(getSelectedDicePixMap(hand.getDice(5)));
}

void MainWindow::on_label_dice6_clicked()
{
    if (engine.currentRoll() == 0)
        return; // don't swithc to selected if we still didn't roll dice

    auto hand = engine.getCurrentHand();
    ui->label_dice6->setPixmap(getSelectedDicePixMap(hand.getDice(6)));
}
