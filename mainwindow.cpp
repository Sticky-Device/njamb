#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMessageBox>

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

void MainWindow::rollDiceButtonClicked()
{
    auto hand = engine.rollDice();

    ui->label_dice1->setText(QString::number(hand.getDice(1)));
    ui->label_dice2->setText(QString::number(hand.getDice(2)));
    ui->label_dice3->setText(QString::number(hand.getDice(3)));
    ui->label_dice4->setText(QString::number(hand.getDice(4)));
    ui->label_dice5->setText(QString::number(hand.getDice(5)));
    ui->label_dice6->setText(QString::number(hand.getDice(6)));

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
    ui->label_dice1->setText("6");
    ui->label_dice2->setText("6");
    ui->label_dice3->setText("6");
    ui->label_dice4->setText("6");
    ui->label_dice5->setText("6");
    ui->label_dice6->setText("6");

    ui->label_free_ones->setText("0");
    ui->label_free_twos->setText("0");
    ui->label_free_threes->setText("0");
    ui->label_free_fours->setText("0");
    ui->label_free_fives->setText("0");
    ui->label_free_sixes->setText("0");
}

