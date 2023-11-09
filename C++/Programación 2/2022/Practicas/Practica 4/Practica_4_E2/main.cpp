#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Colores{
    string nombre;
    int R,G,B;
};
template<typename T>
struct Nodo{
    string nombre;
    int IdNodo;
    T infoNodo;
};
struct persona{
    int edad=0;
    string nombre;

    persona(const int & e, const string & n){edad=e;nombre=n;}
    bool operator >(const persona & per){
            return edad>per.edad;
    }
};
template<typename T>
class Pila{
private:
    vector<T>MiContenedor;
public:
    T pop(void){
        if(MiContenedor.size()==0){
            throw string {"Pila vacia"};
        }else{
            T aux=MiContenedor.back();
            MiContenedor.pop_back();

            return aux;
        }
    }
    void push(const T &dato){
        MiContenedor.push_back(dato);
    }
    void imprimir(void){
        for(T aux:MiContenedor){
            cout<<aux <<endl;
        }
        cout<<endl;
    }
};
//Sobrecarga << para mostrar struct de colores
ostream &operator <<(ostream & os, const Colores &c){
    os<<c.nombre<<endl;
    os<<c.R<<c.G<<c.B<<endl;
    return os;
}

//Sobrecarga << para el nodo y tiene que ser templatizada ya que tiene un campo comodin
template<typename T>
ostream &operator <<(ostream & os,const Nodo<T> &n){
    os<<n.nombre<<n.IdNodo<<endl;
    os<<n.infoNodo<<endl;
    return os;
}
//Sobrecarga << para mostrar por terminal personas
ostream &operator <<(ostream &os,const persona &per){
    os<<per.nombre<<per.edad<<endl;
    return os;
}
//Sobrecarga << para mostrar el vector de T
template<typename T>
ostream &operator <<(ostream &os,const vector<T>&v){
    for(auto e:v){
        os<<e<<endl;
    }
    return os;
}
int main()
{
    Pila<int> MiPilaEnteros;  //Me creo una pila de enteros
    Pila<double> MiPilaDoubles;//Me creo una pila de doubles
    Pila<std::string> MiPilaStrings; //Me creo una pila de strings
    Pila<Nodo<Colores>> MiPilaAmedida; //Y ahora una de nodos con información de colores
    Pila<vector<double>> OtraPila;
    Pila<vector<persona>> OtraMas;

    /*try{
        MiPilaEnteros.pop();
    }
    catch(string s)
    {
        cout<<"Atrapada excepcion: "<<s<<endl;
    }*/

    MiPilaEnteros.push(8);MiPilaEnteros.push(7);MiPilaEnteros.push(6); //Apilamos enteros
    MiPilaEnteros.imprimir();
    MiPilaEnteros.pop(); //Sacamos entero
    MiPilaEnteros.imprimir();

    MiPilaDoubles.push(8.888); MiPilaDoubles.push(7.777); MiPilaDoubles.push(6.666); //Apilamos doubles
    MiPilaDoubles.imprimir();
    MiPilaDoubles.pop(); //Sacamos double
    MiPilaDoubles.imprimir();

    MiPilaStrings.push("Como estais?");MiPilaStrings.push("majos");MiPilaStrings.push("Hola"); //Apilamos strings
    MiPilaStrings.imprimir();
    MiPilaStrings.pop(); //Sacamos strings
    MiPilaStrings.imprimir();

    //Apilamos nodos de colores
    MiPilaAmedida.push({"Nodo 1",101,{"Rojo",255,0,0}});MiPilaAmedida.push({"Nodo 2",102,{"Verde",0,255,0}});MiPilaAmedida.push({"Nodo 3",103,{"Otro",120,60,85}});
    MiPilaAmedida.imprimir();
    MiPilaAmedida.pop(); //Sacamos nodo de colores
    MiPilaAmedida.imprimir();

    //Y si ahora quiero hacer una pila de personas??? no hay problema!! es un template... lo unico cuidado con imprimir...
    //Pero en ordenar ya habíamos sobrecargado << para mostrar por terminal personas ^^

    persona Paco({23,"Paco"});
    persona Luis({34,"Luis"});
    persona Ana({23,"Ana"});

    Pila<persona> Montonera;
    Montonera.push(Paco);Montonera.push(Luis);Montonera.push(Ana);
    Montonera.imprimir();
    Montonera.pop();
    Montonera.imprimir();

    OtraPila.push({1.3,2.0});
    OtraPila.push({0.0});
    OtraPila.push({4.1,2.5,7.0});

    OtraPila.imprimir();

    OtraMas.push({Paco,Luis});
    OtraMas.push({Ana});
    OtraMas.push({Paco,Luis,Ana});
    OtraMas.imprimir();
    OtraMas.pop();
    OtraMas.imprimir();

    return 0;
}
