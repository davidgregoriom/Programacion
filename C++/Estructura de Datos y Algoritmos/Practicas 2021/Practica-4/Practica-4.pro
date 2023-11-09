TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    printjob.cpp \
    printer.cpp

HEADERS += \
    printjob.h \
    printer.h
