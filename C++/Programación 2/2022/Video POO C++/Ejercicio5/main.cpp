#include <iostream>
#include <string>

using namespace std;
class atleta{
private:
    int n;
    float tiempo;
    string nombre;
public:
    atleta(const int &n, const float &tiempo,const string &nombre){
        this->n=n;
        this->tiempo=tiempo;
        this->nombre=nombre;
    }
    atleta(){}
    ~atleta(){}

    int getN() const;
    float getTiempo() const;
    string getNombre() const;
};
ostream &operator <<(ostream & os, atleta & a){
    os<< a.getN()<<endl;
    os<< a.getNombre()<<endl;
    os<< a.getTiempo()<<endl;
}

int main()
{
    atleta * atletas;
    int numeroatletas,numeroatleta;
    float tiempo;
    string nombre;

    cout<<"Digite el numero de atletas a competir: ";
    cin>> numeroatletas;
    atletas=new atleta[numeroatletas];
    for(int i=0;i<numeroatletas;i++){
        cout << "Digite atletas: " << (i+1) <<": "<<endl;

        cout<<"Digite el numero de atleta: ";
        cin>>numeroatleta;
        cout<<endl<<"nombre: ";
        cin>>nombre;
        cout<<endl<<"tiempo: ";
        cin>>tiempo;
        cout<<endl;

        atletas[i]=atleta(numeroatleta,tiempo,nombre);
    }
/*
    for(auto & elem: atletas){
        cout << elem;
    }

*/

}



float atleta::getTiempo() const
{
return tiempo;
}

string atleta::getNombre() const
{
return nombre;
}

int atleta::getN() const
{
return n;
}
