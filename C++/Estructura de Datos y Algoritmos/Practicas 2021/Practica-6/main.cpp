#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

vector<int>la_mitad_del_vector(vector<int> valores,int principio,int final){
    if(principio>=final){
        return  vector<int>(valores.begin()+principio,valores.begin()+final);
    }
}



int BusquedaBinariaRecursiva(const std::vector<int>& v, int valorAbuscar)
{

    int primero{0}, ultimo=v.size()-1;
    int medio = (primero+ultimo)/2;

        if(v.empty()){
            return false;
        }else if(valorAbuscar <v.at(medio)){
           vector<int> nuevo_v = la_mitad_del_vector(v,0,medio);
           return BusquedaBinariaRecursiva(nuevo_v,valorAbuscar);
        }else if(valorAbuscar> v.at(medio)){
            vector<int> nuevo_v = la_mitad_del_vector(v,medio+1,valorAbuscar);
            return BusquedaBinariaRecursiva(nuevo_v,valorAbuscar);
        }else{
            return true;
        }
}


int main()
{
    std::vector<int> miVec{4,2,7,9,1,3,500,-123,0};
    //Para implmentar la búsqueda binaria el vector tiene que estar ordenado
    std::sort(miVec.begin(), miVec.end());
    //Despues de ejecutar std::sort MiVec quedará ordenado de menor a mayor

    int IndiceBusqueda = BusquedaBinariaRecursiva(miVec, 500);
    if(IndiceBusqueda == -1) {
        std::cout << "Valor no encontrado" << std::endl;
    }
    else {
        std::cout << "El valor esta en la posicion: " << IndiceBusqueda<<std::endl;
    }
    return 0;
}
