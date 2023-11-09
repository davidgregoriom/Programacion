/*
   Estructuras de Datos y Algoritmos
   Práctica I

   Alumnos:
    * Jesus Cuesta Bartolome
    * Alejandro Riego Velasco
*/

/*
Implementar de forma recursiva e iterativa:
1.  El cálculo del máximo común divisor de dos números naturales, utilizando el algoritmo de Euclides.
    (El código debe ser implementado en funciones distintas).

2.  Paridad (determinar si un número es par/impar) de un número natural mediante restas.
    Implementa una función que invierta un string que recibe como argumento. (hola -> aloh)

Implementar una función que indique si dos vectores de enteros pasado como argumento son iguales (mismos números, mismas posiciones).
Utilizar iteradores o índices para acceder a los elementos.
Se deben implementar los métodos necesarios, no utilizar código implementado por el compilador.

Implementar un método que nos indique si dos vectores son equivalentes.
Para este ejercicio, dos vectores son equivalentes si tienen los mismo números y éstos aparecen el mismo número de veces en los vectores.

    (1,1,1,2) y (2,1,1,1) son equivalentes

    (1,2) y (1,1,2) no son equivalentes
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mcd_rec(int a, int b) { //MCD EUCLIDES RECURSIVO
    if (b==0) return a;
    return mcd_rec(b, a%b);
}

bool paridad_recursivo (int num){ //PARIDAD RECURSIVA
    if (num==0){
        return true;
    }
    if (num==-1){
        return false;
    }
    num=num-2;

    return paridad_recursivo(num);
}

int mcd_it(int a, int b) { //MCD EUCLIDES ITERATIVO
    int aux;
    while (b!=0) {
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

bool paridad_iterativo(int num){ //PARIDAD ITERATIVO
    if (num==0){
        return true;
    }

    while (num!=-1){
        num=num-2;
        if (num==0){
            return true;
        }
    }
    return false;
}

void InversorStrings1 (const string& texto){ //FORMA 1 INVERTIR STRING

    for(int i =texto.size()-1;i>=0;i--)
    {
        cout<<texto.at(i);
    }
    cout<<endl;
}

string InversorStrings2 (const string& texto){ //FORMA 2 INVERTIR STRING
    string inverso,aux;

    for (int i=texto.size()-1;i>=0;i--)
        {
            aux=texto.at(i);
            inverso.append(aux);
        }

    return inverso;
}

bool VecIguales (const vector<int> &vec1,const vector<int> &vec2) { //VECTORES SON IGUALES
        int aux{0};

        if (vec1.size()==vec2.size()){
            for (auto i=begin(vec1);i<vec1.end();i++){
                //cout<<*i; //pruebas
                if (*i==vec2.at(aux)){
                aux++;
                }
                else {
                    return false;
                }
            }
            return true;
        }
    return false;
}

bool VecEquivalentes (const vector<int> &vec1,const vector<int> &vec2) { //VECTORES SON EQUIVALENTES
    int aux{0};
    vector<int> vecaux;

    if (vec1.size()==vec2.size()){
        for (auto i=begin(vec1);i<vec1.end();i++){
            //cout<<*i; //pruebas
            for (auto j=begin(vec2);j<vec2.end();j++){
                if (*i==*j){
                    aux++;
                    vecaux.push_back(*i);
                }
            }

        }

    }
if (VecIguales(vec1,vecaux)==true){
    return true;
}


return false;
}



int main()
{
    //Valores MCD, paridad y vectores inicializados manualmente
    int x{0},y{0};
    vector<int> vecP1{3,4,7,5},vecP2{3,4,7,5},vecP3{5,4,7,3};
    string txt;

    cout<<"Introduzca dos numeros separados por un espacio: ";
    cin>>x >>y;
    cout<<endl;
    cout<<"Se le mostará el MCD (iterativo,recursivo) y su paridad"<<endl;

    cout<<"El MCD es "<<mcd_rec(x,y)<<endl;
    cout<<"El MCD es "<<mcd_it(x,y)<<endl;

        if (paridad_recursivo(x)==true){
            cout<<"El primer numero es par"<<endl;
        }
         else {
            cout<<"El primer numero es impar"<<endl;
        }


        if (paridad_iterativo(y)==true){
             cout<<"El segundo numero es par"<<endl;
        }
        else {
            cout<<"El segundo numero es impar"<<endl;
     }
    cin.ignore();

    cout<<"Introduzca un string: "<<endl;
    getline(cin, txt );
    InversorStrings1(txt);
    cout<<InversorStrings2(txt)<<endl;

    if(VecIguales(vecP1,vecP2)==true){
        cout<<"Los vectores 1 y 2 son iguales"<<endl;
    }
     else{
        cout<<"Los vectores 1 y 2 no son iguales"<<endl;
    }


    if (VecEquivalentes(vecP1,vecP3)==true){
        cout<<"Los vectores 1 y 3 son equivalentes"<<endl;
    }
     else{
        cout<<"Los vectores 1 y 3 no son equivalentes"<<endl;
    }


    return 0;
}
