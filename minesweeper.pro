#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T16:27:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14

TARGET = minesweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamectrl.cpp \
    gameimg.cpp \
    geometry.cpp \
    gamestatectrlctx.cpp \
    gamestateinitctrl.cpp \
    gamestatectrl.cpp \
    gameblock.cpp \
    gameblocknumber.cpp \
    gameworld.cpp \
    gamemap.cpp \
    gameblockmine.cpp \
    gameworldbuilder.cpp \
    gamescreen.cpp \
    envir.cpp \
    gamestateplayingctrl.cpp \
    gameruler.cpp \
    gamestatewinningctrl.cpp \
    gamestatelosingctrl.cpp \
    gamedialog.cpp

HEADERS  += mainwindow.h \
    gamectrl.h \
    gameimg.h \
    geometry.h \
    bccvtqtutils.h \
    gamestatectrlctx.h \
    gamestateinitctrl.h \
    gamestatectrl.h \
    gameblock.h \
    gameblocknumber.h \
    gameworld.h \
    gamemap.h \
    gameblockmine.h \
    gameworldbuilder.h \
    gamescreen.h \
    envir.h \
    gamestateplayingctrl.h \
    gameruler.h \
    gamestatewinningctrl.h \
    gamestatelosingctrl.h \
    gamedialog.h
