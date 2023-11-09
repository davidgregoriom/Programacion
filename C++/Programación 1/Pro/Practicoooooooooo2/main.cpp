
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main() {
    //1ªMatriz
    int contador=0;
    array<int,9>mat;
    for(int i{0}; i<9;i++){
        cout<< "introduce un elemento " << i+1  << ": ";
        float num;
        cin>>num;
        mat.at(i)= num;
    }
    for(int i=0;i<mat.size();i++){
        if(contador<3){
            cout<<mat.at(i);
            contador++;
        }else{

            cout << "\n";
            cout << mat.at(i);
            contador=1;
        }

    }
    cout <<"\n";

    //Transpuesta

    int espacio=mat.size();


    float raiz = sqrt(espacio);

    cout << raiz;

    array<int,9>transpuesta2;
    for(int i=raiz;i>0;){
        transpuesta2.at((i-1)*i)=mat.at(i-1);
        transpuesta2.at((i-1)*i+1)=mat.at(2*i-1);
        transpuesta2.at((i-i)*i+2)=mat.at(3*i-1);
       i--;
    }

    for(int i=0;i<transpuesta2.size();i++){
        if(contador<3){
            cout<<transpuesta2.at(i);
            contador++;
        }else{

            cout << "\n";
            cout << transpuesta2.at(i);
            contador=1;
        }
    }
    cout<<"\n";

    //2ªMatriz
    array<int,9>mat2;
    for(int i{0}; i<9;i++){
        cout<< "introduce un elemento " << i+1  << ": ";
        float num2;
        cin>>num2;
        mat2.at(i)= num2;
    }
    for(int i=0;i<mat.size();i++){
        if(contador<3){
            cout<<mat2.at(i);
            contador++;
        }else{

            cout << "\n";
            cout << mat2.at(i);
            contador=1;
        }

    }
    cout <<"\n";
    //Multiplicacion:

    array<int,9>multiplicacion{};
    for(int i=0;i<=2;){

        multiplicacion.at(3*i)=mat.at(3*i)*mat2.at(0)+mat.at(3*i+1)*mat2.at(3)+mat.at(3*i+2)*mat2.at(6);
        multiplicacion.at(3*i+1)=mat.at(3*i)*mat2.at(1)+mat.at(3*i+1)*mat2.at(4)+mat.at(3*i+2)*mat2.at(7);
        multiplicacion.at(3*i+2)=mat.at(3*i)*mat2.at(2)+mat.at(3*i+1)*mat2.at(5)+mat.at(3*i+2)*mat2.at(8);
            i++;
        }




    for(int i=0;i<multiplicacion.size();i++){
        if(contador<3){
            cout<<multiplicacion.at(i);
            contador++;
        }else{

            cout << "\n";
            cout << multiplicacion.at(i);
            contador=1;
        }
    }
    cout<<"\n";






    //NS que he hecho
    array<int,9>transpuesta;
    for(int i{0};i<9;){
        transpuesta.at(i)=mat.at(8-i);
        i++;
    }



    for(int i=0;i<transpuesta.size();i++){
        if(contador<3){
            cout<<transpuesta.at(i);
            contador++;
        }else{

            cout << "\n";
            cout << transpuesta.at(i);
            contador=1;
        }
    }
    cout<<"\n";

    //Adjunta
    array<int,9>adj;
    for(int i=0;i<4;i++){
        for(int j=0; i<4;j++){
            if(j==1){

            }else if(j==2){

            }else if(j==3){

            }else{
                break;
            }
        }


    }


    return 0;

}
