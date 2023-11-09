#include <iostream>
#include <memory>


using namespace std;

class Complejo{
public:

    double real{0.0};
    double imaginario{0.0};
    auto sumar(void){
        Complejo aux;

        aux.real=c.real+10;
        aux.imaginario=c.imaginario+10;

        return make_shared<Complejo>(aux);
    }

};
void Imprimir(const shared_ptr<Complejo>&C){
    cout << C->real<<"_"<<C->imaginario<<"j"<<std::endl;
}



int main()
{
   Complejo MiComplejo{22,22};
   Complejo MiOtroComplejo{22,22};
   auto miPunt=Mi;
   Imprimir(miPunt);


}

