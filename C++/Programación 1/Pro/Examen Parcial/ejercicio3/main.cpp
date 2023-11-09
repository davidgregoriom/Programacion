#include <iostream>
#include <array>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int main() {
    //Apartado 1;
    string texto{};
    cout<<"Introduce una frase:\n";
    getline(cin,texto);

    //Apartado 2;

    string textoAlReves {};

    for(int pos = texto.size()-1; pos >= 0; pos--){
        textoAlReves.push_back (texto.at(pos));
    }
    cout << textoAlReves << "\n";

    //Apartado 3;

    string texto2 {};
    texto2= texto;
    int encontrar = texto2.find("as");
    int contador{0};

    while(encontrar != -1){
        contador++;
        encontrar= texto2.find("as", encontrar + 1);

    }
    cout << " se ha encontrado " << contador << "\n";

    //Apartado 4;

    string palabra{};
    vector<string> palabras{};

    for(auto elem:texto){
        if(elem != ' '){
            palabra.push_back(elem);
        }
        else{
            palabras.push_back(palabra);
            palabra = "";
        }

    }
    palabras.push_back(palabra);

    for(auto elem:palabras){
        cout << elem <<"\n";
    }



    return 0;
}

