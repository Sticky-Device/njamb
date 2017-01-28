#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "njambengine.h"
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
    void setSelected(bool s) { selected = s;} // flip selection
    bool isSelected() { return selected; }
    void invertSelection() { selected = !selected;}

    void drawImage();

    void setDice(int value);

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

private:
    void resetUIElements();
    std::vector<int> getSelectedDiceIndices();

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
};

#endif // MAINWINDOW_H
