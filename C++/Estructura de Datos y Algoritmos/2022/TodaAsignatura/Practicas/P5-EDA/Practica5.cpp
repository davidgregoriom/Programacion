/*
   Estructuras de Datos y Algoritmos
   Práctica V

   Alumnos:
    * Alejandro Riego Velasco
    * Jesús Cuesta Bartolomé
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

typedef  shared_ptr<pair<int,int>> Ficha; //Creamos el tipo "Ficha"


vector<Ficha> Generar_fichas(){ //Funcion que genera las fichas de domino
    vector<Ficha> Fichas;
    pair<int, int> ficha{0,0};

    for (ficha.first=0;ficha.first<7;++ficha.first){

         for (ficha.second=ficha.first;ficha.second<7;++ficha.second){

         Fichas.push_back(make_shared<pair<int, int>>(ficha));

        }
    }

    return Fichas;
}

void MostrarFichas(const vector<Ficha>& Fichas){ //Funcion que muestra las fichas del juego
    for (auto const &elem:Fichas){
     cout<<"["<<elem->first<<"|"<<elem->second<<"]"<<" ";
    }
}

void RotarFicha(Ficha & ficha){swap(ficha->first,ficha->second);} //Funcion que gira una ficha (intercambia sus posiciones

bool PuedeAnadirse(const Ficha & ficha,const vector<Ficha> & Fichas){ //Comprueba si se puede añadir una ficha
    return Fichas.empty() || Fichas.at(Fichas.size()-1)->second == ficha->first; //Si está vacío o si enlaza
}

void Ordenar_Domino(vector<Ficha> &Ordenado, vector<Ficha> &Fichas){ //Funcion que genera un ciclo con las fichas de dominó
    for (int i = 0; i < Fichas.size(); ++i) { //Recorro todas las fichas del juego
        Ficha dom = Fichas.at(i); //Almaceno la ficha en la posicion

           if (PuedeAnadirse(dom, Ordenado)) { //Si se puede añadir la ficha
               Ordenado.push_back(dom); //Añadimos la ficha al vector de fichas ordenadas

               Ficha aux = Fichas.at(i); //Almacenamos auxiliarmente la ficha en una variable

               swap(Fichas.at(i),Fichas.back()); //Mandamos la ficha en la posición al fondo
               Fichas.pop_back(); //Borramos la ficha del vector de fichas

               Ordenar_Domino(Ordenado, Fichas); //Intentamos ordenarlo de vuelta

               Fichas.push_back(aux); //Devolvemos la ficha al vector
               swap(Fichas.back(),Fichas.at(i)); //La colocamos en su posición original

               if (Ordenado.size()==28){break;} //Si el vector de fichas ordenadas está con 28 fichas, paramos

               Ordenado.pop_back(); //Si no está lleno, sacamos la ficha ya que ahí no vale
            }

           RotarFicha(dom); //Rotamos y volvemos a probar lo de arriba

           if (PuedeAnadirse(dom, Ordenado)) {
               Ordenado.push_back(dom);

               Ficha aux = Fichas.at(i);

               swap(Fichas.at(i),Fichas.back());
               Fichas.pop_back();

               Ordenar_Domino(Ordenado, Fichas);

               Fichas.push_back(aux);
               swap(Fichas.back(),Fichas.at(i));

                if (Ordenado.size()==28){break;}

               Ordenado.pop_back();
            }
    }
}

int main() {

    vector<Ficha> Fichas,FichasOrdenadas;

    cout<<"Se generan las fichas"<<endl<<endl;

    Fichas=Generar_fichas();

    MostrarFichas(Fichas);

    cout<<endl<<endl;

    cout<<"Se ordenaran de forma ciclica:"<<endl<<endl;

    Ordenar_Domino(FichasOrdenadas,Fichas);

    MostrarFichas(FichasOrdenadas);

    cout<<endl<<endl;




    return 0;
}
