#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "njambengine.h"
#include "results.h"
#include "clickablelabel.h"

#include "downcollumn.h"
#include "freecollumn.h"
#include "upcollumn.h"
#include "updowncollumn.h"
#include "handcollumn.h"
#include "callcollumn.h"


namespace Ui {
class MainWindow;
}

class Dice
{
public:
    void setUp(int value, ClickableLabel* label) { val = value; uiElement = label; }

    void setValue(int value) { val = value; }
    int getValue() { return val; }

    void setSelected(bool s) { selected = s; drawImage(); } // flip selection
    bool isSelected() { return selected; }
    void invertSelection() { setSelected(!selected);}

    void drawImage();

    void setDice(int value);

    void deactivate() { uiElement->setActive(false); setSelected(false);}

private:
    int val;
    ClickableLabel* uiElement;
    bool selected = false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadHeavyStuff();

private slots:
    void rollDiceButtonClicked();

    // menu events
    void on_actionNew_Game_triggered();
    void on_actionAbout_Njamb_triggered();

    // dice clicked events
    void on_label_dice1_clicked();
    void on_label_dice2_clicked();
    void on_label_dice3_clicked();
    void on_label_dice4_clicked();
    void on_label_dice5_clicked();
    void on_label_dice6_clicked();

    void on_label_free_ones_hovered();
    void on_label_free_ones_unhovered();

    void on_label_free_twos_hovered();
    void on_label_free_twos_unhovered();

    void on_label_free_threes_hovered();
    void on_label_free_threes_unhovered();

    void on_label_free_fours_hovered();
    void on_label_free_fours_unhovered();

    void on_label_free_fives_hovered();
    void on_label_free_fives_unhovered();

    void on_label_free_sixes_hovered();
    void on_label_free_sixes_unhovered();

    void on_label_free_max_hovered();
    void on_label_free_max_unhovered();

    void on_label_free_min_hovered();
    void on_label_free_min_unhovered();

    void on_label_free_triling_hovered();
    void on_label_free_triling_unhovered();

    void on_label_free_straight_hovered();
    void on_label_free_straight_unhovered();

    void on_label_free_full_hovered();
    void on_label_free_full_unhovered();

    void on_label_free_poker_hovered();
    void on_label_free_poker_unhovered();

    void on_label_free_yamb_unhovered();
    void on_label_free_yamb_hovered();

    void on_label_free_ones_clicked();
    void on_label_free_twos_clicked();
    void on_label_free_threes_clicked();
    void on_label_free_fours_clicked();
    void on_label_free_fives_clicked();
    void on_label_free_sixes_clicked();
    void on_label_free_max_clicked();
    void on_label_free_min_clicked();
    void on_label_free_triling_clicked();
    void on_label_free_straight_clicked();
    void on_label_free_full_clicked();
    void on_label_free_poker_clicked();
    void on_label_free_yamb_clicked();

    void on_label_down_ones_clicked();
    void on_label_down_ones_hovered();
    void on_label_down_ones_unhovered();

    void on_label_down_twos_clicked();
    void on_label_down_twos_hovered();
    void on_label_down_twos_unhovered();

    void on_label_down_threes_clicked();
    void on_label_up_yamb_clicked();
    void on_label_up_yamb_hovered();

    void on_label_up_yamb_unhovered();
    void on_label_up_poker_clicked();
    void on_label_up_poker_hovered();

    void on_label_up_poker_unhovered();

    void on_label_up_full_clicked();

    void on_label_up_full_hovered();

    void on_label_up_full_unhovered();

    void on_label_updown_max_clicked();

    void on_label_updown_max_hovered();

    void on_label_updown_max_unhovered();

    void on_label_updown_min_clicked();

    void on_label_updown_min_hovered();

    void on_label_updown_min_unhovered();

    void on_label_updown_triling_clicked();

    void on_label_updown_triling_hovered();

    void on_label_updown_triling_unhovered();

    void on_label_updown_sixes_clicked();

    void on_label_updown_sixes_hovered();

    void on_label_updown_sixes_unhovered();

    void on_label_hand_ones_clicked();

    void on_label_hand_ones_hovered();

    void on_label_hand_ones_unhovered();

    void on_label_call_ones_clicked();

    void on_label_call_ones_hovered();

    void on_label_call_ones_unhovered();

    void on_label_hand_twos_clicked();

    void on_label_hand_twos_hovered();

    void on_label_hand_twos_unhovered();

    void on_label_hand_threes_clicked();

    void on_label_hand_threes_hovered();

    void on_label_hand_threes_unhovered();

    void on_label_hand_fours_clicked();

    void on_label_hand_fours_hovered();

    void on_label_hand_fours_unhovered();

    void on_label_hand_fives_clicked();

    void on_label_hand_fives_hovered();

    void on_label_hand_fives_unhovered();

    void on_label_hand_sixes_clicked();

    void on_label_hand_sixes_hovered();

    void on_label_hand_sixes_unhovered();

    void on_label_hand_max_clicked();

    void on_label_hand_max_hovered();

    void on_label_hand_max_unhovered();

    void on_label_hand_min_clicked();

    void on_label_hand_min_hovered();

    void on_label_hand_min_unhovered();

    void on_label_hand_triling_clicked();

    void on_label_hand_triling_hovered();

    void on_label_hand_triling_unhovered();

    void on_label_hand_straight_clicked();

    void on_label_hand_straight_hovered();

    void on_label_hand_straight_unhovered();

    void on_label_hand_full_clicked();

    void on_label_hand_full_hovered();

    void on_label_hand_full_unhovered();

    void on_label_hand_poker_clicked();

    void on_label_hand_poker_hovered();

    void on_label_hand_poker_unhovered();

    void on_label_hand_yamb_clicked();

    void on_label_hand_yamb_hovered();

    void on_label_hand_yamb_unhovered();

    void on_label_call_twos_clicked();

    void on_label_call_twos_hovered();

    void on_label_call_twos_unhovered();

    void on_label_call_threes_clicked();

    void on_label_call_threes_hovered();

    void on_label_call_threes_unhovered();

    void on_label_call_fours_clicked();

    void on_label_call_fours_hovered();

    void on_label_call_fours_unhovered();

    void on_label_call_fives_clicked();

    void on_label_call_fives_hovered();

    void on_label_call_fives_unhovered();

    void on_label_call_sixes_clicked();

    void on_label_call_sixes_hovered();

    void on_label_call_sixes_unhovered();

    void on_label_call_max_clicked();

    void on_label_call_max_hovered();

    void on_label_call_max_unhovered();

    void on_label_call_min_clicked();

    void on_label_call_min_hovered();

    void on_label_call_min_unhovered();

    void on_label_call_triling_clicked();

    void on_label_call_triling_hovered();

    void on_label_call_triling_unhovered();

    void on_label_call_straight_clicked();

    void on_label_call_straight_hovered();

    void on_label_call_straight_unhovered();

    void on_label_call_full_clicked();

    void on_label_call_full_hovered();

    void on_label_call_full_unhovered();

    void on_label_call_poker_clicked();

    void on_label_call_poker_hovered();

    void on_label_call_poker_unhovered();

    void on_label_call_yamb_clicked();

    void on_label_call_yamb_hovered();

    void on_label_call_yamb_unhovered();

    void on_label_updown_fives_clicked();

    void on_label_updown_fives_hovered();

    void on_label_updown_fives_unhovered();

    void on_label_updown_fours_clicked();

    void on_label_updown_fours_hovered();

    void on_label_updown_fours_unhovered();

    void on_label_updown_threes_clicked();

    void on_label_updown_threes_hovered();

    void on_label_updown_threes_unhovered();

    void on_label_updown_twos_clicked();

    void on_label_updown_twos_hovered();

    void on_label_updown_twos_unhovered();

    void on_label_updown_ones_clicked();

    void on_label_updown_ones_hovered();

    void on_label_updown_ones_unhovered();

    void on_label_updown_straight_clicked();

    void on_label_updown_straight_hovered();

    void on_label_updown_straight_unhovered();

    void on_label_updown_full_clicked();

    void on_label_updown_full_hovered();

    void on_label_updown_full_unhovered();

    void on_label_updown_poker_clicked();

    void on_label_updown_poker_hovered();

    void on_label_updown_poker_unhovered();

    void on_label_updown_yamb_clicked();

    void on_label_updown_yamb_hovered();

    void on_label_updown_yamb_unhovered();

    void on_label_down_threes_hovered();

    void on_label_down_threes_unhovered();

    void on_label_down_fours_clicked();

    void on_label_down_fours_hovered();

    void on_label_down_fours_unhovered();

    void on_label_down_fives_clicked();

    void on_label_down_fives_hovered();

    void on_label_down_fives_unhovered();

    void on_label_down_sixes_clicked();

    void on_label_down_sixes_hovered();

    void on_label_down_sixes_unhovered();

    void on_label_down_max_clicked();

    void on_label_down_max_hovered();

    void on_label_down_max_unhovered();

    void on_label_down_min_clicked();

    void on_label_down_min_hovered();

    void on_label_down_min_unhovered();

    void on_label_down_triling_clicked();

    void on_label_down_triling_hovered();

    void on_label_down_triling_unhovered();

    void on_label_down_straight_clicked();

    void on_label_down_straight_hovered();

    void on_label_down_straight_unhovered();

    void on_label_down_full_clicked();

    void on_label_down_full_hovered();

    void on_label_down_full_unhovered();

    void on_label_down_poker_clicked();

    void on_label_down_poker_hovered();

    void on_label_down_poker_unhovered();

    void on_label_down_yamb_clicked();

    void on_label_down_yamb_hovered();

    void on_label_down_yamb_unhovered();

    void on_label_up_ones_clicked();

    void on_label_up_ones_hovered();

    void on_label_up_ones_unhovered();

    void on_label_up_twos_clicked();

    void on_label_up_twos_hovered();

    void on_label_up_twos_unhovered();

    void on_label_up_threes_clicked();

    void on_label_up_threes_hovered();

    void on_label_up_threes_unhovered();

    void on_label_up_fours_clicked();

    void on_label_up_fours_hovered();

    void on_label_up_fours_unhovered();

    void on_label_up_fives_clicked();

    void on_label_up_fives_hovered();

    void on_label_up_fives_unhovered();

    void on_label_up_sixes_clicked();

    void on_label_up_sixes_hovered();

    void on_label_up_sixes_unhovered();

    void on_label_up_max_clicked();

    void on_label_up_max_hovered();

    void on_label_up_max_unhovered();

    void on_label_up_min_clicked();

    void on_label_up_min_hovered();

    void on_label_up_min_unhovered();

    void on_label_up_triling_clicked();

    void on_label_up_triling_hovered();

    void on_label_up_triling_unhovered();

    void on_label_up_straight_clicked();

    void on_label_up_straight_hovered();

    void on_label_up_straight_unhovered();

private:
    void nextRound();
    void updateResultsForCollumn(Rules::Collumn collumn);
    void updateResults();
    void resetGame();
    void resetUIElements();
    void handleCallFieldClicked();
    bool gameCompleted();
    std::vector<int> getSelectedDiceIndices();

private:
    QLabel* getNumbersSumElementForCollumn(Rules::Collumn collumn);
    QLabel* getMinMaxSumElementForCollumn(Rules::Collumn collumn);
    QLabel* getMajorSumElementForCollumn(Rules::Collumn collumn);

private:
    int final_sum = 0;
    int free_numbers_sum = 0;
    int free_minmax_sum = 0;
    int free_major_sum = 0;

private:
    NjambEngine engine;
    Ui::MainWindow *ui;

private:
    Dice dice1;
    Dice dice2;
    Dice dice3;
    Dice dice4;
    Dice dice5;
    Dice dice6;

private:
    DownCollumn downCollumn;
    FreeCollumn freeCollumn;
    UpCollumn upCollumn;
    UpDownCollumn upDownCollumn;
    HandCollumn handCollumn;
    CallCollumn callCollumn;

private:
    Results results;
};

#endif // MAINWINDOW_H
