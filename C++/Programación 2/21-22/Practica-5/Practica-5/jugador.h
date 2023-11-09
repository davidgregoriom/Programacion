#ifndef JUGADOR_H
#define JUGADOR_H
#include "bolsa.h"
#include <vector>

class Jugador
{
public:
    Jugador();
    Jugador(int numero_apostado_,int suma_puntos_,bool juego_);

    bool jugada();
    bool jugada(int juego);

    int getSuma_puntos() const;
    void setSuma_puntos(int value);

    int getNumero_apostado() const;
    void setNumero_apostado(int value);

protected:
    int numero_apostado;
    int suma_puntos;
    int juego;
};


#endif // JUGADOR_H
