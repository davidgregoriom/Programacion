TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    articulos.cpp \
    libros.cpp \
    publicacion.cpp

HEADERS += \
    articulos.h \
    libros.h \
    publicacion.h
