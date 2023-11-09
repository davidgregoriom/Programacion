#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class PunteroListo{
private:
    T* punt;
public:
    PunteroListo(){punt=nullptr;} //Constructor por defecto
    PunteroListo(T in){punt=new T(in);} //Reserva dinÃ¡mica para almacenar la info
    ~PunteroListo(){delete punt;} //Liberamos la memoria

    T& operator*(){ //Sobrecarga operador *
                    //Al devolver la referencia T& podremos usar el operador para leer y escribir informaciÃ³n en la indirecciÃ³n del puntero
        if(punt!=nullptr)
        {
            return *punt;
        }
        else
        {//Si el puntero tiene nullptr=> lanzamos excepciÃ³n
            throw string{"Segmentation fault"};
        }
    }

};

template<typename T>
ostream& operator<<(ostream&os, const vector<T>& v)
{//Para poder usar * sobre un puntero a vector de tipos simples necesitamos sobrecargar << para vector<T>
    for(T e:v)
    {
        os<<e<<" ";
    }
    os<<endl;

    return os;
}

int main()
{
    PunteroListo<int> miPunt;
    PunteroListo<int> miOtroPunt(666);

    try{
        cout<<"PunteroListo a int inicializado con el valor 666"<<endl;
        cout<<*miOtroPunt<<endl;
        cout<<&miOtroPunt<<endl;

        cout<<"PunteroListo a int sin inicializar"<<endl;
        cout<<&miPunt<<endl;
        cout<<*miPunt<<endl; //Estamos intentando indireccionar el puntero nulo=> Segmentation fault
    }
    catch(string e)
    {
        cout<<"Excepcion capturada: "<<e<<endl;
        cout<<endl;
    }

    cout<<"Prueba escritura en indirecciÃ³n del puntero"<<endl;
    *miOtroPunt=200;  //
    cout<<*miOtroPunt<<endl;

    cout<<"Prueba PunteroListo con vector de enteros"<<endl;
    PunteroListo<vector<double>> miPuntVectDouble({1,2,3});
    cout<<*miPuntVectDouble<<endl;
    cout<<&miPuntVectDouble<<endl;

    cout<<"Prueba PunteroListo con vector de char"<<endl;
    PunteroListo<vector<char>> miPuntVectChar({'h','o','l','a'});
    cout<<*miPuntVectChar<<endl;
    cout<<&miPuntVectChar<<endl;

    cout<<"Terminando..."<<endl;
    return 0;
}
