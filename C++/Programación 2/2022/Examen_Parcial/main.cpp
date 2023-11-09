#include <iostream>
#include <memory>
#include <vector>
#include "funciones.h"

using namespace std;

int main()
{
    bool continuar{true};
    Fraccion operando1,operando2, resultado, prueba(12,4);
    std::vector<std::shared_ptr<Fraccion>> Historico;

    resultado=prueba.simplificar(prueba);
    cout<<"Probando simplificacion... "<<resultado<<endl;

    try{
        while(continuar)
        {
            switch(menu())
            {
            case 0: //salir
                continuar=false;
                break;
            case 1: //Introducir operandos
                //try{ //Haría falta "vigilar "todo el switch-case"???
                    std::cin>>operando1;
                    std::cin>>operando2;
                //}
                //catch(...){cout<<"Algo ha ido mal, pero puedo continuar..."<<endl;};
                break;
            case 2: //Sumar Operandos
                resultado=operando1+operando2;
                std::cout<<"La suma es: "<<resultado<<endl;

                Historico.push_back(make_shared<Fraccion>(resultado));
                break;
            case 3:
                resultado=operando1-operando2;
                std::cout<<"La resta es: "<<resultado<<endl;
                Historico.push_back(make_shared<Fraccion>(resultado));
                break;
            case 4:
                resultado=operando1*operando2;
                std::cout<<"La multiplicacion es: "<<resultado<<endl;
                Historico.push_back(make_shared<Fraccion>(resultado));
                break;
            case 5:
                std::cout<<"Operando 1: "<<operando1;
                std::cout<<"Operando 2: "<<operando2;
                break;
            }
        }
    }
    catch(std::string e)
    {
        std::cout<<"Excepcion tipo string capturada... "<<e<<endl;
    }
    /*catch(int i) //Que pasa si no tenemos un catch del tipo que "lanzamos"???
    {
        std::cout<<"Excepcion tipo int capturada... "<<i<<endl;
        switch (i) {
        case 0:
            cout<<"El denominador es 0."<<endl;
            break;
        case 1:
            cout<<"El denominador es negativo."<<endl;
            break;
        default:
            cout<<"Excepción tipo int no contemplada :("<<endl;

        }
    }*/

    std::cout<<Historico; //Antes de finalizar el programa mostramos el histórico de resultados

    return 0;
}
