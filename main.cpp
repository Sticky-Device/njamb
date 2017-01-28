#include "mainwindow.h"
#include <QApplication>
#include <QRect>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    auto screenGeometry = QApplication::desktop()->availableGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y);
    w.show();
    w.loadHeavyStuff();

    a.exec();
}
