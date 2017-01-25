#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "njambengine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void rollDiceButtonClicked();
    void on_actionNew_Game_triggered();
    void on_actionAbout_Njamb_triggered();
    void on_label_dice1_clicked();

    void on_label_dice2_clicked();

    void on_label_dice3_clicked();

    void on_label_dice4_clicked();

    void on_label_dice5_clicked();

    void on_label_dice6_clicked();

private:
    void resetUIElements();

private:
    NjambEngine engine;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
