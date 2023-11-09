TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    slack.cpp \
    tipodato.cpp \
    elementolistasimple.cpp

HEADERS += \
    slack.h \
    tipodato.h \
    elementolistasimple.h
