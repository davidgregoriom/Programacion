#include <iostream>
#include <array>

using namespace std;

int menu(){
    cout<<"Elige una opcion:\n";
    cout<<"1 Salir del programa\n";
    cout<<"2 Introducir matrices\n";
    cout<<"3 Sumar matrices y mostrar la suma por pantalla\n";
    cout<<"4 Restar matrices y mostrar la resta por pantalla\n";
    cout<<"5 Calcular determinante matriz 3x3 y mostrarlo por pantalla\n";
    cout<<"6 Imprimir las 2 matrices (inicialmente, antes de que el usuario les asigne valor serán todo 0)\n";

    int opcion{0};

    cin >>opcion;

    return opcion;
}

array<float,9>Pedirmatriz(){
    array<float,9>matriz;
    for(int fila{0};fila<9;fila++){
        cout <<fila+1;
        cin>> matriz.at(fila);

    }
    return matriz;
}

array<float,9>suma(array<float,9>m1,array<float,9>m2){
    array<float,9>resultado;
    for(int fila{0};fila<9;fila++){
        resultado.at(fila)=m1.at(fila)+m2.at(fila);

    }
    return resultado;
}


array<float,9>resta(array<float,9>m1,array<float,9>m2){
    array<float,9>resultado;
    for(int fila{0};fila<9;fila++){
        resultado.at(fila)=m1.at(fila)-m2.at(fila);

    }
    return resultado;
}
float determinante(){}


int main(){
    array<float,9>matriz1;
    array<float,9>matriz2;
    int op = menu();
    while(op !=1){
    if(op==2){
        matriz1 = Pedirmatriz();
        matriz2 = Pedirmatriz();
    }else if(op==3){
        array<float,9>lasuma = suma(matriz1,matriz2);
    }else if(op==4){
        array<float,9>laresta = resta(matriz1,matriz2);
    }else if(op==5){

    }
    op =menu();
    }
    return 0;
}
