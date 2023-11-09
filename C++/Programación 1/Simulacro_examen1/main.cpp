#include <iostream>
#include <array>
#include<string>
#include<functional>

using namespace std;


struct libro {
    string autor;
    string titulo;
    array<int,3>tags;
    int ubicacion;
    int indice;
};

auto Dar_de_alta=  [&] ( const string, const string, const array<int,3>, const int,const int){



};

int main(){

Dar_de_alta(libro);

}
