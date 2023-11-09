 #include "matrix.h"
#include <array>
#include <iostream>

using namespace  std;


Matriz3x3::Matriz3x3()
{
    array<array<float,3>,3>matri{};
}

void Matriz3x3::print() const {
   for(auto elem:mat){
       for(auto elem2:elem){
           cout << elem2<<"\t";
       }
        cout << "\n";

   }
}

int Matriz3x3::determinant() const {
    int determinante = (mat.at(0).at(0) * mat.at(1).at(1) * mat.at(2).at(2) +mat.at(1).at(0) * mat.at(2).at(1) * mat.at(0).at(2) + mat.at(0).at(1) *mat.at(1).at(2) * mat.at(2).at(0)) - (mat.at(0).at(2) * mat.at(1).at(1) * mat.at(2).at(0) + mat.at(1).at(2) * mat.at(2).at(1) * mat.at(0).at(0) + mat.at(1).at(0) * mat.at(0).at(1) * mat.at(2).at(2));

     cout << determinante;
     return determinante;

}

shared_ptr<Matriz3x3::mat> Matriz3x3::add(shared_ptr<Matriz3x3::mat> a, shared_ptr<Matriz3x3::mat> b)
{
    shared_ptr<Matriz3x3> suma = make_shared<Matriz3x3>();
    for(int i{0};i<3;i++){
        for(int j{0};j<3;j++){
            int elem = a->get(i,j)+b->get(i,j);
            suma ->set(i,j,elem);
        }
    }

}

int Matriz3x3::getMat(int row ,int col){
    int elem;
    if(row <0 || row >2) throw "esta el elemento de la fila";
    else if(col <0 || col >2) throw "esta el elemento de la columna";
    else elem=mat.at(row).at(col);
    return elem;

}

void Matriz3x3::setMat(int row,int col,int value)
{
    if(row <0 || row >2) throw "esta el elemento de la fila";
    else if(col <0 || col >2) throw "esta el elemento de la columna";
    else mat.at(row).at(col)=value;
}

