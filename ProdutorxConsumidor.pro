#-------------------------------------------------
#
# Project created by QtCreator 2014-05-06T14:23:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProdutorxConsumidor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread1.cpp \
    semaforo.cpp \
    thread2.cpp \
    sobre.cpp

HEADERS  += mainwindow.h \
    thread1.h \
    semaforo.h \
    thread2.h \
    sobre.h

FORMS    += mainwindow.ui \
    sobre.ui
