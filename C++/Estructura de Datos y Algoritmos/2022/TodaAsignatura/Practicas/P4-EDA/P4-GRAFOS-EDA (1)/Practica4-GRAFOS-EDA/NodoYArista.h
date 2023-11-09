/*
   Estructuras de Datos y Algoritmos
   Práctica IV

   Alumnos:
    * Jesús Cuesta Bartolomé
    * Alejandro Riego Velasco
*/


#ifndef NODOYARISTA_H
#define NODOYARISTA_H

#include <iostream>
#include <vector>

#include <random> //Para IP aleatoria
#include <ctime>


using namespace std;

struct IP{ //GENERAR IP DE FORMA ALEATORIA
    int n1{0};
    int n2{0};
    int n3{0};
    int n4{0};

    IP(){
        constexpr int MAX = 255;
        n1=rand() % MAX;
        n2=rand() % MAX;
        n3=rand() % MAX;
        n4=rand() % MAX;
    }
};

std::ostream& operator<<(std::ostream& os, IP const & a){ //SOBRECARGA PARA MOSTRAR IP
  os<<a.n1<<"."<<a.n2<<"."<<a.n3<<"."<<a.n4<<endl;
  return os;
}


class Router {
   public:

  Router(string nom) {
    nombre=nom;
    anterior=NULL;
    DistanciaIncio=INT_MAX;
    conectado=false;
  };
  Router() {
    nombre="Vacio";
    anterior=NULL;
    DistanciaIncio=INT_MAX;
    conectado=false;
  };

  IP ip;
  string nombre;
  bool conectado; // Para comprobar si está aislado
  Router* anterior; // Para Dijkstra->Sirve para mirar las conexiones
  int DistanciaIncio; // Para Dijkstra->Otorga el peso a los nodos
};

std::ostream& operator <<(std::ostream& os, Router const & a){ //SOBRECARGA PARA MOSTRAR ROUTER
    os<<"IP: "<<a.ip;
    os<<"Nombre: "<<a.nombre<<endl;

  return os;
}

bool operator == (const IP &a,const IP &b){
    if (a.n1==b.n1 and a.n2==b.n2 and a.n3==b.n3 and a.n4==b.n4){
        return true;
    }
    return false;
}

bool operator != (const IP &a,const IP &b){
    return !(a==b);
}


class Conexion {
   public:
  Conexion(Router* Rt1, Router* Rt2,int time){
    Router1=Rt1;
    Router2=Rt2;
    tiempo=time;
  }

  bool Conectados(Router* Rt1, Router* Rt2) { //Comprueba si existe conexion entre 2 routers
    return (
      (Rt1 == this->Router1 && Rt2 == this->Router2) ||
      (Rt1 == this->Router2 && Rt2 == this->Router1));
  }

  Router* Router1;
  Router* Router2;
  int tiempo; //Lo usamos como "peso" de la conexion
};













#endif // NODOYARISTA_H
