#include <iostream>

using namespace std;
class Vehiculo{
private:
    string marca,modelo;
    float precio;
public:
    Vehiculo(const string & marca,const string &modelo,const float &precio){
        this->marca=marca;
        this->modelo=modelo;
        this->precio=precio;
    }
    Vehiculo(){}

    float getPrecio() const{
        return precio;
    }
    string getMarca() const{
        return marca;
        }

    string getModelo() const{
        return modelo;
        }
};
ostream & operator <<(ostream & os,const Vehiculo & v){
    os<< v.getMarca()<<endl;
    os<< v.getModelo()<<endl;
    os<< v.getPrecio()<<endl;
}

int main()
{
    Vehiculo* coches;
    int numero=0;
    string marca,modelo;
    float precio;
    cout<<"Cuantos?"<< endl;
    cin>>numero;
    coches= new Vehiculo[numero];
    for(int i=0;i<numero;i++){
        cout << "datos del vehiculo:"<<i<<endl;
        cout << "marca?: ";
        cin >> marca;
        cout<<endl <<"modelo?: ";
        cin>>modelo;
        cout<<endl <<"precio?: ";
        cin>>precio;
        cout << endl;
        coches[i]= Vehiculo(marca,modelo,precio);
    }
    /*for(const auto & c:coches){
        cout<<c;
    }*/
    return 0;
}




