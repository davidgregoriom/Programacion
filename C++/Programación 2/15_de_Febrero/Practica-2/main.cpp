#include <iostream>
#include <array>
#include "matrix.h"

using namespace std;


int main()
{

    cout << "Introduce :";
    array<float,3>matriz;
    try {
        for(int i {0};i<3 ; i++){
            int elem;
            cin>> elem;
            matriz.at(i)= elem;
        }

    Matriz3x3  a(matriz);



    for(int i {0};i<3 ; i++){
        int elem;
        cin>> elem;
        matriz.at(i)= elem;
    }
    Matriz3x3 b(matriz);






    shared_ptr<Matriz3x3> p1=make_shared<Matriz3x3>(a);
    shared_ptr<Matriz3x3> p2=make_shared<Matriz3x3>(b);
    shared_ptr<Matriz3x3> pT=matriz(p1,p2);





    pT->print();
    cout <<pT->determinant();
    }catch (string a){
        if(a=="esta el elemento de la fila")cout <<"la fila tiene demasiado grande\n";
        else if(a=="esta el elemento de la columna")cout << "la columna tiene demasiado grande\n";
    }
}
