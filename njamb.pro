#-------------------------------------------------
#
# Project created by QtCreator 2017-01-18T00:31:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = njamb
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    dicehand.cpp \
    njambengine.cpp \
    clickablelabel.cpp

HEADERS  += mainwindow.h \
    dicehand.h \
    njambengine.h \
    clickablelabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    dice.qrc
