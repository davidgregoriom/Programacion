TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrizgeneral.cpp \
    matrizdiagonal.cpp \
    matriz3x3.cpp \
    matriz2x2.cpp

HEADERS += \
    matrizgeneral.h \
    matrizdiagonal.h \
    matriz3x3.h \
    matriz2x2.h
