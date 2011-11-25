#-------------------------------------------------
#
# Project created by QtCreator 2011-06-10T15:47:31
#
#-------------------------------------------------

QT       += core network
QT       -= gui

INCLUDEPATH += /usr/include/

LEXSOURCES =

TARGET = u2d_base

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    agent.cpp \
    sense_body.cpp \
    sensor.cpp \
    visualsensor.cpp \
    connection.cpp \
    parserbase.cpp \
    parser-init.cpp \
    parser-server-param.cpp \
    server_param.cpp \
    parser-sense_body.cpp \
    see.cpp


HEADERS += \
    agent.h \
    sense_body.h \
    sensor.h \
    visualsensor.h \
    connection.h \
    parserbase.h \
    server_param.h \
    see.h
#    parser.h









