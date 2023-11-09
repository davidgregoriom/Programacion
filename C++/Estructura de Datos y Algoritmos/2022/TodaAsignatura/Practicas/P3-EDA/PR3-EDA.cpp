#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
   Estructuras de Datos y Algoritmos
   Práctica II

   Alumnos:
    * Alejandro Riego Velasco
    * Jesús Cuesta Bartolomé
*/

//Ejercicio 1
//Resolver los siguientes retos de la web "acepta el reto". Se debe implementar un algoritmo recursivo y otro iterativo (los dos)

//PROBLEMA 574. Gritos en Halloween

//ITERATIVO

string gritosIT(int n){
    string mid{"BUH"},aux{"BUH"},ext;

    if (n==0){
        return "No hay grito";
    }

    if (n==1){
        return mid;
    }

    do {
         ext=aux;
         mid=mid.insert(2,"U");
         aux=ext+mid+ext;
         n--;
    }
    while (n!=1);

    return ext+" "+mid+" "+ext;
}

//RECURSIVO

string gritosREC(int n,string& mid,string& aux,string& ext){
    if (n==0){
        return "No hay grito";
    }

    if (n==1){
        return ext+" "+mid+" "+ext;;
    }

    if (n!=1){
         ext=aux;
         mid=mid.insert(2,"U");
         aux=ext+mid+ext;
         return (gritosREC(n-1,mid,aux,ext));
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PROBLEMA 252. ¿Acaso hubo buhos acá?

//ITERATIVO

bool palindroIT(string const &cadena){
    bool espalindromo= true;
    int a= 0;
    int b= cadena.length()-1;

    while(a <= b && espalindromo ){

        if( cadena.at(a)== ' '){
            a++;
        }
        else if(cadena.at(b)==' '){
            b--;
        }
        else{
            if (tolower(cadena.at(a))!= tolower(cadena.at(b))){
                espalindromo = false;
            }
            a++;
            b--;
        }
    }
    return espalindromo;
}

//RECURSIVO

bool palindroREC(string const & cadena, int a, int b ){
    bool espalindromo = true;
    if (a >=b && tolower(cadena.at(a))==tolower(cadena.at(b))){
        return espalindromo;
    }

    if (cadena.at(a)==' '){
        a++;
    }
    else if (cadena.at(b)== ' '){
        b--;
    }
    else {
        if (tolower(cadena.at(a)) != tolower(cadena.at(b))){
            espalindromo = false;
        }
        a++;
        b--;
    }

    return palindroREC(cadena, a, b) && espalindromo ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ejercicio 2       Resolver de forma iterativa

//PROBLEMA 246. Búsqueda de polidivisibles.

bool polidivisibilidad (int N){

    int ncif{0},D{N},i{1},aux,a,b,c{1};
        while (D>0){    //Calculamos el número máximo de dígitos
             D=D/10;
             ncif++;
        }
        do{
             aux=pow (10,ncif-1);
             a=N/aux;
             b=a%c;
            if (b!=0)
                 return false;
             ncif--;
             i++;
             c++;
        }
        while (ncif!=0);
        return true;
}


//PROBLEMA 141. Paréntesis balanceados

bool balance_parentesis (const string& dato){
    string dataux = dato;
    int cont{0};
   for (string::iterator i=dataux.begin();i<dataux.end(); ++i){
        if (*i=='(' || *i=='{' ||  *i=='[' ){

           cont=1;
           for (string::iterator j=i;j+1<dataux.end();++j){
               if (*j== ')' || *i=='}' || *i==']'){
                   dataux.erase(i);
                   dataux.erase(j);
                   cont=0;
                   break;
                }
           }
        }
    }
    if (cont==0)
        return true;
    return false;
}


int main()
{
    string mid{"BUH"},aux{"BUH"},ext, balance{"({[]})()"};

    cout<<"Ejemplo problema 574 iterativo: "<<gritosIT(3)<<endl; //Ejemplo con el número 3
    cout<<"Ejemplo problema 574 recursivo: "<<gritosREC(4,mid,aux,ext)<<endl; //Ejemplo con el número 4

    if(palindroIT("Acaso hubo buhos aca")==true){ //Ejemplo iterativo frase
        cout<<"La frase introducida es palindroma"<<endl;
    }
    else cout<<"La frase introducida NO es palindroma"<<endl;

    if(palindroREC("Acaso hubo buhos aca",0,0)==true){ //Ejemplo recursivo frase
        cout<<"La frase introducida es palindroma"<<endl;
    }
    else cout<<"La frase introducida NO es palindroma"<<endl;

    if(polidivisibilidad(1020)==true){ //Ejemplo polidivisivilidad con el numero 1020
        cout<<"El numero intoducido es polidivisible"<<endl;
    }
    else cout<<"El numero intoducido NO es polidivisible"<<endl;

    if(balance_parentesis(balance)==true){ //Ejemplo paréntesis balanceados
        cout<<"La entrada esta correctamente balanceada"<<endl;
    }
    else cout<<"La entrada NO esta correctamente balanceada"<<endl;


     return 0;
    }
