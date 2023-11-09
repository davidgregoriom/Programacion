#include "jugador.h"
#include "bolsa.h"

using namespace std;

Jugador::Jugador()
{

}

Jugador::Jugador(int numero_apostado_, int suma_puntos_, bool juego_){
    numero_apostado=numero_apostado_;
    suma_puntos=suma_puntos_;
    juego=juego_;
}



bool Jugador::jugada(int juego)
{
    if(juego==1){
        return true;
    }else{
        return false;
    }
}

int Jugador::getSuma_puntos() const
{
    return suma_puntos;
}

void Jugador::setSuma_puntos(int value)
{
    Bolsa a;
    auto v_bolas = a.getBolas();
    int sorteo = rand() % v_bolas.size();

    value= value+ v_bolas.at(sorteo);
    a.pop_sacarBola(sorteo);
    suma_puntos = value;
}

int Jugador::getNumero_apostado() const
{
    return numero_apostado;
}

void Jugador::setNumero_apostado(int value)
{
   if(value<10||value>50){
       cout << "repite el numero"<< endl ;
       cin >>  value;
       return setNumero_apostado(value);
   }else{
    numero_apostado = value;
}
}
