#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class animal{
private:
    int edad;
    string nombre;
public:
    animal(){edad=0;}
    animal(const string & n,int e){nombre=n;edad=e;}
    virtual ~animal(){}

    int getEdad() const{return edad;}
    string getNombre() const{return nombre;}
    virtual string hablar()const =0;
    virtual string soy()const =0;


};
class persona:public animal{
public:
    persona():animal(){}
    persona(const string & n, int e):animal(n,e){}
    string hablar() const {return "Me llamo "+getNombre();}
    string soy()const {return "persona";}
};
class perro:public animal{
private:
    string amo;
public:
    perro():animal(){}
    perro(const string & n,const string & a,int e):animal(n,e){amo=a;}
    string hablar() const{return "Guau";}
    string soy()const {return "perro";}
    string getAmo()const {return amo;}
};
class gato:public animal{
public:
    gato():animal(){}
    gato(const string & n,int e):animal(n,e){}
    string hablar() const {return "Miau";}
    string soy()const {return "gato";}
};
shared_ptr<persona> CrearPersona(const string & n,int e){
    return make_shared<persona>(n,e);
}
shared_ptr<perro> CrearPerro(const string & n,const string & a,int e){
    return make_shared<perro>(n,a,e);
}
shared_ptr<gato> CrearGato(const string & n,int e){
    return make_shared<gato>(n,e);
}
ostream& operator <<(ostream & os,const shared_ptr<animal> &a){
    os<<a->hablar()<<endl;
    os<<a->getNombre()<<endl;
    os<<a->getEdad()<<endl;


    if(a->soy()=="persona"||a->soy()=="gato"){

    }else if(a->soy()=="perro"){
        shared_ptr<perro>aux=dynamic_pointer_cast<perro>(a);
        if(aux!=nullptr){
            os<<aux->getAmo()<<endl;
        }
    }
    return os;

}

int menu()
{
    int op{0};
    std::cout<<"1.Persona"<<std::endl;
    std::cout<<"2.Perro"<<std::endl;
    std::cout<<"3.Gato"<<std::endl;
    std::cout<<"Que animal quieres introducir?: ";
    std::cin>>op;cin.ignore();

    if(op>0 && op<4)
    {
        return op;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<shared_ptr<animal>>grupo;
    bool continuar=true;
    int opcion=0,edad=0;
    string nombre,amo;

    while(continuar){
        opcion=menu();
        cout<<"nombre?: ";
        getline(cin,nombre);
        cout<<"edad?: ";
        cin>>edad;cin.ignore();

        switch (opcion) {

        case 1:
            grupo.push_back(CrearPersona(nombre,edad));
            break;
        case 2:
            cout<<"amo: ";
            getline(cin,amo);
            grupo.push_back(CrearPerro(nombre,amo,edad));
            break;
        case 3:
            grupo.push_back(CrearGato(nombre,edad));
            break;
        default:
            cout<<"elige otra opcion "<< endl;
        }
        cout <<"¿Continuar?:[0->NO; 1->SI]";
        cin >>continuar;cin.ignore();
    }
    for(const auto & e:grupo){
        cout << e;
    }
    return 0;
}
