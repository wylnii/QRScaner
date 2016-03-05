#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T21:26:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRScaner
TEMPLATE = app


SOURCES += main.cpp\
<<<<<<< HEAD
        widget.cpp \
    qrwidget.cpp \
    qrencode/qrencode.c \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rscode.c \
    qrencode/split.c

HEADERS  += widget.h \
    qrwidget.h \
    qrencode/qrencode.h \
    qrencode/bitstream.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode_inner.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rscode.h \
    qrencode/split.h
=======
        widget.cpp

HEADERS  += widget.h
>>>>>>> a0704cdfb69a2f6500e41ff290152659cde81b18

FORMS    += widget.ui

include(QZXing.pri)
