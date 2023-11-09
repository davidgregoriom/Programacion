TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    recorrido.cpp \
    grafo_de_las_estaciones.cpp \
    queue.cpp \
    elementolistadoble.cpp

HEADERS += \
    recorrido.h \
    grafo_de_las_estaciones.h \
    queue.h \
    elementolistadoble.h
