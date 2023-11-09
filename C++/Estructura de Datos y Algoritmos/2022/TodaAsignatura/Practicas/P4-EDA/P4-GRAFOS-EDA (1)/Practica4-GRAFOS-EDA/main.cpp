/*
   Estructuras de Datos y Algoritmos
   Práctica IV

   Alumnos:
    * Jesús Cuesta Bartolomé
    * Alejandro Riego Velasco
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "NodoYArista.h"
#include "Grafo.h"


#define INT_MAX 10000000 //Declaramos infinito -> Dijkstra

using namespace std;

int main() {
    //Generamos los 5 routers
    Router* Pepe=new Router("Pepe");
    Router* Juan=new Router("Juan");
    Router* Rodri=new Router("Rodri");
    Router* Jose=new Router("Jose");
    Router* Dani=new Router("Dani");

    Red Uno,Dos;
    Uno.AnadirRouter(Pepe);
    Uno.AnadirRouter(Juan);
    Uno.AnadirRouter(Rodri);
    Uno.AnadirRouter(Jose);
    Uno.AnadirRouter(Dani);

    //Conectamos dejando aislado a Dani
    Uno.ConectarRouters(Pepe,Jose,18);
    Uno.ConectarRouters(Pepe,Juan,8);
    Uno.ConectarRouters(Juan,Rodri,2);
    Uno.ConectarRouters(Rodri,Jose,3);

    cout<<"Se le mostrara la red"<<endl;
    cout<<Uno<<endl;

    cout<<"Comprobar conectividad (1=Hay nodos aislados, 0=Hay nodos aislados): "<<Uno.Conectividad()<<endl;

    cout<<"Conectamos el nodo aislado (Dani)"<<endl;

    Uno.ConectarRouters(Pepe,Dani,1);

    cout<<"Comprobar conectividad (1=Hay nodos aislados, 0=Hay nodos aislados): "<<Uno.Conectividad()<<endl<<endl;

    //Comprobamos si se trata de una red malla

    cout<<"Comprobar red malla (1=Es red de malla, 0=No hay red de malla): "<<Uno.ConectividadMalla()<<endl;

    cout<<"Conectamos todos los nodos formando red de malla"<<endl;
    Uno.ConectarRouters(Pepe,Rodri,7);
    Uno.ConectarRouters(Dani,Jose,9);
    Uno.ConectarRouters(Dani,Rodri,2);
    Uno.ConectarRouters(Dani,Juan,3);
    Uno.ConectarRouters(Juan,Jose,12);

    cout<<"Comprobar red malla (1=Es red de malla, 0=No hay red de malla): "<<Uno.ConectividadMalla()<<endl<<endl;

    cout<<"Vamos a probar Dijkstras"<<endl;

    Uno.Dijkstras(Pepe); //Pepe como primer elemento

    cout<<"La ruta mas corta a Jose es: "<<endl;
     //Mostramos la ruta más corta a Jose
    Uno.RutaMasCortaDijk(Jose);

    cout<<Uno;

    cout<<"Vamos a probar Kruskal: "<<endl<<endl;

    Dos=kruskal(Uno);

    cout<<Dos;

    return 0;
}

