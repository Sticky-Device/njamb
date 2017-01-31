#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "njambengine.h"
#include "results.h"
#include "clickablelabel.h"


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

private:
    void nextRound();
    void updateResults(Rules::Collumn, Rules::YambField, int value);
    void resetUIElements();
    std::vector<int> getSelectedDiceIndices();

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
    Results results;
};

#endif // MAINWINDOW_H
