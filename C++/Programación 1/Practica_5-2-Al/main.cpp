#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string cadena;
    std::cout<<"Introduce la operación: ";
    getline(std::cin, cadena);

    if(cadena.at(0)=='+' || cadena.at(0)=='-'){ //empiezo con un signo
        char primerNumero=cadena.at(1);
        std::string cad;
        cad += primerNumero;
        int num=std::stoi(cad);

        if(cadena.at(0)=='-'){
            num=num*-1;
        }
        for(int i=2; i<cadena.size(); i+=2){ //Avanza de 2 en 2, ya que los singos aparecen cada dos espacios
            char signo=cadena.at(i);
            char numero=cadena.at(i+1);
            std::string cad;
            cad+=numero;
            int n=std::stoi(cad);;

            if(signo =='-'){
                num=num - n;
            }
            if(signo=='+'){
                num=num + n;
            }

        }
        std::cout<<"El resultado es: " <<num<<"\n";
    }else{ //empiezo con un número
        char numero=cadena.at(0);
        std::string cad;
        cad += numero;
        int num=std::stoi(cad);

        for(int i=1; i < cadena.size(); i+=2){ //Avanza de 2 en 2, ya que los singos aparecen cada dos espacios
            char signo=cadena.at(i);
            char numero=cadena.at(i+1);
            std::string cad;
            cad+=numero;
            int n=std::stoi(cad);;

            if(signo =='-'){
                num=num - n;
            }
            if(signo=='+'){
                num=num + n;
            }
            //std::cout<<"El resultado es: " <<num<<"\n";
        }
        std::cout<<"El resultado es: " <<num<<"\n";
    }


}
