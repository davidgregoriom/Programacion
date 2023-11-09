TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sudoku.cpp \
    tablero.cpp

HEADERS += \
    sudoku.h \
    tablero.h

DISTFILES += \
    Sudoku \
    sudoku
