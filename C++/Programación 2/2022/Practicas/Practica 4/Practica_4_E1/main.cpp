#include <vector>
#include <iostream>
#include <string>

using namespace std;


template<typename T>
class Contenedor{
private:
    vector<T>contenedor;
public:
    Contenedor(const vector<T>& in){contenedor=in;}
    vector<T>Ordenar(void){
        vector<T>ordenado=contenedor;
        for(int i=0;i<contenedor.size();i++){
            for(int j=0;j<contenedor.size()-1;j++){
                if(ordenado.at(j)>ordenado.at(j+1)){
                    swap(ordenado.at(j),ordenado.at(j+1));
                }
            }
        }
        return ordenado;
    }
};



struct persona{
    string nombre;
    int edad=0;
    persona (const int &e,const string &n){edad=e;nombre=n;}
    bool operator >(persona const &per){
        return edad>per.edad;
    }
};

ostream & operator <<(ostream &os,const persona & per){
    os<<per.nombre << per.edad<< endl;
    return os;
}


int main()
{
    //Ordenamos int
    Contenedor<int> miContenedor({9,8,2,-1,1,1,0}); //Creo un contenedor de enteros

    std::vector<int> ord=miContenedor.Ordenar(); //Llamo al método ordenar
    for(auto elem:ord)
    {//muestro el vector ordenado
        std::cout<<elem<<"_";
    }
    cout<<endl;

    //Ordenamos char
    Contenedor<char> miContenedor2(vector<char>{'a','w','0','0','b','t'}); //Lo mismo con char

    std::vector<char> ord2=miContenedor2.Ordenar();
    for(auto elem:ord2)
    {
        std::cout<<elem<<"_";
    }
    cout<<endl;

    //Ordenamos personas por edad
    vector<persona> grupo;
    persona Paco({23,"Paco"});
    persona Luis({34,"Luis"});
    persona Ana({23,"Ana"});

    grupo.push_back(Paco);
    grupo.push_back(Luis);
    grupo.push_back(Ana);

    Contenedor<persona> miContenedor3(grupo); //Ahora con personas
    std::vector<persona> ord3=miContenedor3.Ordenar(); //Para poder llamar a Ordenar tengo que definir como funciona < o > con las personas
                                                       //El estándar de C++ no sabe compararlas => sobrecarga del operador
    for(auto elem:ord3)
    {
        std::cout<<elem<<"_"; //Podemos imprimir personar porque hemos sobrecargado << con la estructura persona
    }
    cout<<endl;

    vector<string> VecStrings;

    VecStrings.push_back("Manolo Perez");
    VecStrings.push_back("Manolo Lopez");
    VecStrings.push_back("Pepe Perez");

    Contenedor<string> miContenedor4(VecStrings);

    auto ord4=miContenedor4.Ordenar();
    for(auto elem:ord4)
    {
        std::cout<<elem<<"_"; //Podemos imprimir personar porque hemos sobrecargado << con la estructura persona
    }
    cout<<endl;

    return 0;
}
