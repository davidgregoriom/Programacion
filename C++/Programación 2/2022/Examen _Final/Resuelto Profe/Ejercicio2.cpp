#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class animal{
private:
    std::string nombre;
    int edad;
public:
    animal(){edad=0;}
    animal(const std::string &n, int e){edad=e;nombre=n;}
    virtual ~animal(){};

    std::string getNombre() const{return nombre;}
    int getEdad() const{return edad;}
    virtual std::string hablar() const=0;
    virtual string WhoAmI () const=0; //PodrÃ­amos usar hablar para el downcasting
};

class persona:public animal{
private:
public:
    std::string hablar() const {return "Me llamo "+getNombre();}
    persona(const std::string &n, int e):animal(n,e){}
    persona():animal(){};
    string WhoAmI() const {return "persona";}
};

class  perro:public animal{
private:
    std::string amo;
public:
    perro():animal(){};
    perro(const std::string &n,const std::string &a, int e):animal(n,e){amo=a;}
    std::string hablar() const {return "Guau";}
    string WhoAmI ()const{return "perro";}

    std::string getAmo()const{return amo;}
};

class  gato:public animal{
private:
public:
    gato():animal(){};
    gato(const std::string &n, int e):animal(n,e){}
    std::string hablar() const{return "Miau";}
    string WhoAmI () const{return "gato";}
};

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

shared_ptr<persona> CrearPersona(const string& n,int e){
    return make_shared<persona>(n,e);
}

shared_ptr<perro> CrearPerro(const string& n,const string& a,int e){
    return make_shared<perro>(n,a,e);
}

shared_ptr<gato> CrearGato(const string& n,int e){
    return make_shared<gato>(n,e);
}

ostream& operator<<(ostream &os,const shared_ptr<animal> &a)
{//Sobrecarga << para puntero animal
    os<<"********************"<<endl;

    os<<a->hablar()<<endl;
    os<<"Nombre: "<<a->getNombre()<<endl;
    os<<"Edad: "<<a->getEdad()<<endl;

   if(a->WhoAmI()=="persona" || a->WhoAmI()=="gato")
   {//Las personas y los gatos tienen la misma informaciÃ³n para mostrar por terminal
       //Nada que mostrar, personas y gatos no aÃ±aden variables en la cadena de herencia
       //Este if no harÃ­a falta
   }
   else if(a->WhoAmI()=="perro")
   {//Los perros tienen un campo mÃ¡s => su dueÃ±o

       shared_ptr<perro> aux= dynamic_pointer_cast<perro>(a);
       if(aux!=nullptr)
       {
            os<<"Mi amo es: "<<aux->getAmo()<<endl;
       }
   }
   os<<"********************"<<endl;

   return os;
}


int main()
{
    std::vector<shared_ptr<animal>> grupo;

    bool continuar{true};
    int opcion{0},edad{0};
    string nombre,amo;


    while(continuar)
    {
        opcion=menu();
        cout<<"Nombre?: ";
        getline(std::cin,nombre);
        cout<<"Edad?: ";
        std::cin>>edad; cin.ignore();

        switch(opcion)
        {
            case 1://persona
                grupo.push_back(CrearPersona(nombre,edad));
            break;
            case 2://perro
                cout<<"Nombre de su amo?: ";
                getline(std::cin,amo);
                grupo.push_back(CrearPerro(nombre,amo,edad));
            break;
            case 3://gato
                grupo.push_back(CrearGato(nombre,edad));
            break;
            default:
            std::cout<<"Opcion no contemplada"<<std::endl;
        }

        std::cout<<"Desea continuar introduciendo informacion?[0->NO; 1->SI]: ";
        std::cin>>continuar;
        std::cin.ignore(); //No harÃ­a falta porque el menu ya limpia el buffer y es lo primero que se ejecuta en el bucle
    }

    //Antes de la finalizaciÃ³n del programa mostramos la informaciÃ³n de la variable contenedor de punteros a animales
    for(const auto &e:grupo)
    {
        std::cout<<e;
    }

    return 0;
}
