TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    persona.cpp \
    empleados.cpp \
    responsableequipo.cpp \
    trabajadores.cpp

HEADERS += \
    persona.h \
    empleados.h \
    responsableequipo.h \
    trabajadores.h
