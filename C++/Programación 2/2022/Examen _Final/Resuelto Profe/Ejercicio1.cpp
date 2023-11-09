#include <iostream>
#include <vector>

using namespace std;

class Polinomio
{
    private:
        std::vector<double> constantes;
    public:
        Polinomio(){};
        Polinomio(int grado, const std::vector<double> &ctes)
        {
            if(grado!=ctes.size()-1)
            {//Un polinomio de grado 2 tendrÃ¡ 3 ctes a*X^2+b*X+c => [a b c]
                //Si son diferentes lanzamos una excepciÃ³n de tipo string
                throw std::string{"Error"};
            }
            //Si estÃ¡ todo bien, inicializamos las variables encapsuladas en la clase
            constantes=ctes;
        }

        Polinomio operator +(const Polinomio &poli)
        {//Sobrecarga del operador + para sumar polinomios
            int tam1=constantes.size();
            int tam2=poli.getGrado()+1;

            vector<double> aux2{poli.getConst()},aux1{getConst()};
            //Para sumar polinomios sumamos las constantes del mismo grado de ambos polinomios

            //Redimensionamos el vector auxiliar al tamaÃ±o de constantes del polinimio de mayor grado
            //aÃ±adiendo ceros en las constantes que no existen
            if(tam1>tam2)
            {
                aux2.resize(tam1,0);
            }
            else
            {
                aux1.resize(tam2,0);
            }
            //Ahora mismo las dos variables auxiliares tienen el mismo tamaÃ±o

            for(int i{0};i<aux1.size();i++)
            {//Recorremos sumando las constantes
                aux1.at(i)=aux1.at(i)+aux2.at(i);
            }

            try{
                Polinomio retorno(aux1.size()-1,aux1); //Creamos un polinomio de nombre retorno con el grado y constantes calculados
                return retorno;
            }
            catch(const std::string &s)
            {//No deberÃ­amos llegar aquÃ­ ya que estamos creando el polinomio con el size()-1 del vector
                std::cout<<"Error"<<std::endl;
            }
        }

        int getGrado() const {return constantes.size()-1;}
        vector<double> getConst() const{return constantes;}
        void setConst(const vector<double> c){constantes=c;}
};

ostream& operator<<(ostream &os, const Polinomio &poli)
{//Sobrecarga del operador << para Polinomio
    auto ctes=poli.getConst();

    for(int i{0};i<poli.getGrado()+1;i++)
    {
        if(i==0)
        {//Mostramos el valor correspondiente a X^0
            os<<ctes.at(0);
        }
        else
        {
            if(ctes.at(i)>0)
            {//Si es > 0 => aÃ±adimos el signo + en el buffer
                os<<"+"<<ctes.at(i)<<"*X^"<<i;
            }
            else if(ctes.at(i)<0)
            {//Si es < 0 no hace falta aÃ±adirlo
                os<<ctes.at(i)<<"*X^"<<i;
            }
            else
            {//Si es 0 no mostramos nada
                //No harÃ­a falta este else
            }
        }
    }
    return os;
}

istream& operator>>(istream &is, Polinomio &poli)
{//Sobrecarga del operador >> para Polinomio
    std::vector<double> aux;
    int grado{0},cte;
    std::cout<<"Grado del polinomio?: ";
    std::cin>>grado;
    std::cout<<std::endl;

    for(int i{0};i<grado+1;i++)
    {//Capturamos las ctes de cada grado
        std::cout<<"Introduce la cte para el grado "<<i<<" del polinomo: ";
        std::cin>>cte;
        aux.push_back(cte);
    }

    try
    {//No deberÃ­a ocurrir la excepciÃ³n, ya que capturamos tantas ctes como grado+1 en el bucle
        poli=Polinomio(grado,aux);
    }
    catch (const std::string &s) {
            std::cout<<"Excepcion: "<<s;
    }

    return is;
}

int main()
{//Probamos todo lo implementado segÃºn indica el enunciado
    Polinomio pol1,pol2(3,{1,2,3,4}),pol3; //Constructores
    std::cin>>pol1; //Sobrecarga de >>

    pol3=pol1+pol2; //Sobrecarga operador +

    std::cout<<"Polinomio 1: "<<pol1<<std::endl;   //Sobrecarga de <<
    std::cout<<"Polinomio 2: "<<pol2<<std::endl;
    std::cout<<"Polinomio 3: "<<pol3<<std::endl;

    std::cout<<"Ejemplo excepcion constructor: "<<std::endl;
    try{
        Polinomio mal(4,{1,2,3,4,5,6,7}); //ExcepciÃ³n del constructor
    }
    catch(const std::string &e)
    {
        std::cout<<"Excepcion capturada: "<<e<<std::endl;
    }

    return 0;
}
