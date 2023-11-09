/*
   Estructuras de Datos y Algoritmos
   Práctica IV

   Alumnos:
    * Jesús Cuesta Bartolomé
    * Alejandro Riego Velasco
*/


#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "NodoYArista.h"

using namespace std;

class Red{
    public:

    Red(){};

    //Añadir routers y conectarlos
    void AnadirRouter(Router* router){Routers.push_back(router);};

    void ConectarRouters(Router* Rt1, Router* Rt2,int time){
        Conexiones.push_back(new Conexion(Rt1,Rt2,time));
        Rt1->conectado=true;
        Rt2->conectado=true;
    }

    bool Conectividad();//Comprueba si existen routers aislados (si existen -> =false , ya que no hay conectividad total)

    bool ConectividadMalla(); //Comprueba si se trata de una red de malla (No contemplamos conexiones repetidas)

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Metodos de la red->Necesarios para Dijkstras

    void Dijkstras(Router* router);

    Router* ExtraerMinimoDijk(); //Devuelve el router con el minimo valor y lo saca de la coleccion

    vector<Router*>* RoutersAdyacentesRestantesDijk(Router* router); //Devuelve un puntero a un vector que da los routers adyacentes a un router

    bool Contiene(Router* router); //Comprueba si existe un router en la red

    int DistanciaAdy(Router* router1, Router* router2); //Distancia entre 2 routers

    void RutaMasCortaDijk(Router* destino); //Muestra la ruta más corta a un router

    //Contenedores
    vector<Router *> Routers;
    vector<Conexion *> Conexiones;

};

std::ostream& operator <<(std::ostream& os, Red const & a){ //SOBRECARGA PARA MOSTRAR LOS ROUTERS DE LA RED

    for (auto elem:a.Routers){
        os<<*elem<<endl;
    }
    os<<"Las conexiones de la red son: "<<endl;
    for (auto elem:a.Conexiones){
        os<<elem->Router1->nombre<<"->"<<elem->Router2->nombre<<endl;
    }

  return os;
}

//VERIFICAR SI TODOS LOS NODOS TIENEN CONECTIVIDAD

bool Red::Conectividad(){
    for (auto elem:Routers){
        if (elem->conectado==false){
            return false;
        }
    }
    return true;
}

//VERIFICAR TOPOLOGIA DE RED EN MALLA

bool Red::ConectividadMalla(){
    if (Conexiones.size()==((Routers.size()*(Routers.size()-1))/2)){ //Cada nodo como maximo puede tener (n*(n-1)/2) conexiones
        return true;
    }
    return false;
}

//DIJKSTRAS

void Red::Dijkstras(Router* router) {
    router->DistanciaIncio=0;                            //Definimos el primer nodo
    vector<Router*> aux=Routers;                   //Copiamos el vector de (punteros a)routers
    while (Routers.size() > 0) {                         //Mientras que haya routers
    Router* minimo = ExtraerMinimoDijk();      //1. Almacenamos el minimo
    vector<Router*>* RoutersAdyacentes =RoutersAdyacentesRestantesDijk(minimo); //2.Buscamos los adyacentes al minimo

    for (int i = 0; i < RoutersAdyacentes->size(); ++i) { //3.Recorremos el vector de routers adyacentes al minimo
      Router* adyacente = RoutersAdyacentes->at(i);     //Cogemos un router (adyacente al minimo)
      int distancia = DistanciaAdy(minimo, adyacente) + minimo->DistanciaIncio; //Sumamos las distancias

      if (distancia < adyacente->DistanciaIncio) { //Si la distancia del adyacente al incio es menor que la del minimo, los cambiamos
        adyacente->DistanciaIncio = distancia;
        adyacente->anterior = minimo;
      }
    }
    delete RoutersAdyacentes;                           //Borramos el (puntero a)vector de routers adyacentes
  }                                                                       //Restauramos el vector original de routers, ya que hemos trabajado con el, pero los nuevos pesos
    Routers=aux;                                                //siguen almacenados al tratarse de punteros
}

Router* Red::ExtraerMinimoDijk() {
  if (Routers.size() == 0) return NULL; //Si está vacio no hay ningun router en la red,devolvemos NULL

  int PosicionMinima = 0;
  Router* minimo = Routers.at(0); //El router con el menor peso es el primero
  for (int i = 1; i < Routers.size(); ++i) { //Recorremos el vector de routers
    Router* actual = Routers.at(i); //Miramos el router en la posicion
    if (actual->DistanciaIncio < minimo->DistanciaIncio) { //Si el router tiene menos distancia al incio que el primero del vector
      minimo = actual;                                                         //El minimo pasa a ser el "nuevo"
      PosicionMinima = i;                                                    //Y almacenamos la posicion
    }
  }
  Routers.erase(Routers.begin() + PosicionMinima); //Lo borramos de la lista de routers para
  return minimo;                                                          //Devolvemos el puntero al router minimo
}

vector<Router*>* Red::RoutersAdyacentesRestantesDijk(Router* router) { //
  vector<Router*>* RoutersAdyacentes = new vector<Router*>();   //Creamos un vector de (punteros a)routers donde metemos los routers

  for (int i = 0; i < Conexiones.size(); ++i) { //Recorremos el vector conexiones
    Conexion* conex = Conexiones.at(i);     //Cogemos una conexion
    Router* adyacente = NULL;                   //Creamos un puntero al router adyacente (vacío)
    if (conex->Router1 == router) {             //Comprobamos en la conexion si está ese Router, si es así, la añadimos al vector de adyacentes
      adyacente = conex->Router2;
    }
    else if (conex->Router2 == router) {
      adyacente = conex->Router1;
    }
    if (adyacente && Contiene(adyacente)) {             //Comprobamos si es adyacente y si ese router es parte de la red
      RoutersAdyacentes->push_back(adyacente);
    }
  }
  return RoutersAdyacentes;                                    //Devolvemos el vector de routers adyacentes
}

bool Red::Contiene(Router* router){
for (int i = 0; i < Routers.size(); ++i) {
      if (router == Routers.at(i)) {return true;}
    }
    return false;
  }

int Red::DistanciaAdy(Router* router1, Router* router2){
    for (int i = 0; i <Conexiones.size(); ++i) {
      Conexion* conex = Conexiones.at(i);
      if (conex->Conectados(router1, router2)) {return conex->tiempo;}
    }
    return -1;  // No deberia pasar nunca ->Solo si esos routers no están conectados
  }

void Red::RutaMasCortaDijk(Router* destino){
    Router* anterior = destino;
    cout << "Distancia desde el inicio : "<< destino->DistanciaIncio << endl;
    while (anterior) {
      cout << anterior->nombre << " ";
      anterior = anterior->anterior;
    }
    cout << endl;
  }

//KRUSKAL

bool ComparadorConex(Conexion* con1,Conexion* con2){return con1->tiempo<con2->tiempo;}

bool Check_and_addConex(Conexion* conex,vector<Router*> &routers){
    int coinc=0;
    for (auto elem:routers){

        if (conex->Router1==elem){
            coinc+=1;
        }

        if (conex->Router2==elem){
            coinc+=2;
        }
    }
    if (coinc==0){ //No existe ninguno de los 2 routers en las conexiones
        routers.push_back(conex->Router1);
        routers.push_back(conex->Router2);
        return true;
    }
    if (coinc==1){ //Añadimos la conexion, ya que el router 2 no estaba conectado
        routers.push_back(conex->Router2);
        return true;
    }
    if (coinc==2){ //Añadimos la conexion , ya que el router 1 no estaba conectado
        routers.push_back(conex->Router1);
        return true;
    }
    if (coinc==3){ //Si están ambos routers en el vector-> Ya existe conexion entre ellos de menor peso

        return false;
    }
    return false; //Nunca debería pasar este caso
}

Red kruskal(Red red) {
    Red MST;

    sort(red.Conexiones.begin(), red.Conexiones.end(),ComparadorConex);  // Conexiones ordenadas por su peso

    for (int i = 0; i < red.Conexiones.size(); i++) { //Recorremos las conexiones
        if (Check_and_addConex(red.Conexiones.at(i),MST.Routers)){
            MST.Conexiones.push_back(red.Conexiones.at(i));
            }
    }

    return MST;
}


#endif // GRAFO_H
