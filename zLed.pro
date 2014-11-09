#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T15:41:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lamps
TEMPLATE = app


SOURCES += main.cpp\
        leds.cpp \
    zled.cpp

HEADERS  += leds.h \
    zled.h

FORMS    += leds.ui
