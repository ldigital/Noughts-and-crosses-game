#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T07:38:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = noughts_and_crosses
TEMPLATE = app


SOURCES += main.cpp\
        game_setup.cpp \
    chosen_player.cpp \
    game_data.cpp \
    game.cpp \
    game_result_display.cpp

HEADERS  += game_setup.h \
    chosen_player.h \
    game_data.h \
    game.h \
    game_result_display.h

FORMS    += game_setup.ui \
    chosen_player.ui \
    game.ui \
    game_result_display.ui
