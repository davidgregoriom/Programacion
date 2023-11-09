#include "complejo.h"
#include "funciones.h"
#include <vector>
#include <memory>

int main()
{
    Complejo Operando1, Operando2; //Que constructor de la clase Complejo estamos utilizando?
    Complejo resultado=Operando1; //Y ahora??

    std::vector<std::shared_ptr<Complejo>> HistoricoComplejos;
    std::vector<std::shared_ptr<double>> HistoricoModulos;

    double auxReal{0.0},auxImag{0.0};
    bool salir{0};

    while(!salir)
    {
        switch(menu())
        {
            case 1://Introducir complejos
                std::cout<<"Primer numero complejo:"<<std::endl;
                std::cout<<"Parte real..."<<std::endl;
                std::cin>>auxReal;
                std::cout<<"Parte imaginaria..."<<std::endl;
                std::cin>>auxImag;

                Operando1.setPReal(auxReal); Operando1.setPImag(auxImag);

                //2 veces lo mismo????
                std::cout<<"Segundo numero complejo:"<<std::endl;
                std::cout<<"Parte real..."<<std::endl;
                std::cin>>auxReal;
                std::cout<<"Parte imaginaria..."<<std::endl;
                std::cin>>auxImag;

                Operando2.setPReal(auxReal); Operando2.setPImag(auxImag);

                // o .... de esta otra forma.... mejor no?

                //Operando1=IntroducirComplejoTerminal();
                //Operando2=IntroducirComplejoTerminal();

                break;
            case 2://Sumar
                resultado=Operando1.sumar(Operando2);
                resultado.imprimir();

                HistoricoComplejos.push_back(std::make_shared<Complejo>(resultado));
                break;
            case 3://Módulo
                std::cout<<Operando1.modulo()<<std::endl;
                std::cout<<Operando2.modulo()<<std::endl;

                HistoricoModulos.push_back(std::make_shared<double>(Operando1.modulo()));
                HistoricoModulos.push_back(std::make_shared<double>(Operando2.modulo()));
                break;
            case 4://División
                try
                {//"vigilamos" el código que puede generar una excepción
                    resultado=Operando1.dividir(Operando2);
                    resultado.imprimir();
                    HistoricoComplejos.push_back(std::make_shared<Complejo>(resultado));
                }
                catch (std::string e)
                {
                    std::cout<<"Excepcion capturada. El error es: "<<e<<std::endl;
                }
                break;
            case 5://Salir
                salir=true;
                break;
            default:
                std::cout<<"Opcion no contemplada"<<std::endl;
        }

    }

    MostrarHistorico(HistoricoComplejos,HistoricoModulos);

    return 0;
}
