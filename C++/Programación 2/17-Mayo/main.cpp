#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

using namespace std;

class Figura{

public:
    Figura(string tipo):tipo{tipo}{}
    virtual ~Figura();

    string getTipo()const{return tipo;}

    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
private:
    string tipo;


};
class Cuadrado: public Figura{
public:
    Cuadrado(float lado): Figura{"Cuadrado"},lado {lado}{}

    float getArea() const;
    float getPerimetro() const;
private:
    float lado;

};
class Circulo: public Figura{
public:
    Circulo(float radio): Figura{"Círculo"},radio {radio}{}

    float getArea() const;
    float getPerimetro() const;

private:
    float radio;
};

int main()
{
    vector<shared_ptr<Figura>> figuras;
    char c ='z';
    while(c!='x'){
        cout<< "¿?\n";
        cin >> c;
        if(c=='c'){
            cout << "Introduce el radio:\n";
            float r;cin >> r;
            figuras.push_back(make_shared<Circulo>(Circulo{r}));
        }else if(c=='q'){
            cout << "Introduce el lado:\n";
            float l;cin >> l;
            figuras.push_back(make_shared<Cuadrado>(Cuadrado{l}));
        }
    }
    for(auto elem:figuras){
        cout << "Soy un "<< elem->getTipo() << "\n";
        cout << "Mi area es" << elem-> getArea() << "n";
        cout << "Mi perimetro es "<< elem ->getPerimetro() << "\n";
    }

    return 0;
}

float Cuadrado::getArea() const
{
    return lado*lado;
}

float Cuadrado::getPerimetro() const
{
    return 4*lado;
}

float Circulo::getArea() const
{
    return M_PI *radio*radio;
}

float Circulo::getPerimetro() const
{
    return 2*M_PI*radio;
}
