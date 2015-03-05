#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T20:52:38
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = qtbotantest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

#INCLUDEPATH += .
#INCLUDEPATH += $$_PRO_FILE_PWD_/../

include(qtcore.pri)
#include(../qbsqlcipher/qbsqlcipher.pri)



win32:LIBS += -l../clib/qslduno

HEADERS +=
