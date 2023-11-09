TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    square.cpp \
    triangle.cpp

HEADERS += \
    figure.h \
    square.h \
    triangle.h
