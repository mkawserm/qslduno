#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T16:55:03
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = qslduno
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS +=

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = ../clib
include(qslduno.pri)
