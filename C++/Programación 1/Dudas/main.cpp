#include <iostream>
#include <vector>

using namespace std;
#include <iostream>
#include <string>
#include <array>
using namespace std;
int buscador_de_palabras1(string cadena,int pos,int letra){

    for(auto elem: cadena){
      pos++;
      if (elem == ' '){
        if(cadena.at(pos+1) == letra){
          int next_espacio = cadena.find (' ', pos+1);
          if(next_espacio != -1){

           std::cout << cadena.substr(pos+1 , next_espacio - pos -1) << " ";

         }else{
           std::cout << cadena.substr(pos+1);
         }

        }
      }
    }

}

int main(){
    string cadena;
    cout<<"Introduce una cadena de texto:\n";
    int pos{-1};
    int letra1{'a'};
    int letra2{'e'};
    int letra3{'i'};
    int letra4{'o'};
    int letra5{'u'};
      getline (std::cin,cadena);
        buscador_de_palabras1(cadena,pos,letra1);
        buscador_de_palabras1(cadena,pos,letra2);
        buscador_de_palabras1(cadena,pos,letra3);
        buscador_de_palabras1(cadena,pos,letra4);
        buscador_de_palabras1(cadena,pos,letra5);
    }
