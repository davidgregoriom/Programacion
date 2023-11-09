#include <iostream>
#include <vector>
#include <memory>


using namespace std;

class Contacto{
public:
    Contacto(){
        nombre = "";
        apellido1 = "";
        telefono = "";
        email = "";
        nacimiento = "";
    }
    Contacto(const string &nom,const string &apell,const string & telef,const string & gmail, const string & fecha){
        setNombre(nom);
        setApellido1(apell);
        setTelefono(telef);
        setEmail(gmail);
        setNacimiento(fecha);
    }
    string getNombre() const;
    void setNombre(const string &value);

    string getApellido1() const;
    void setApellido1(const string &value);

    string getTelefono() const;
    void setTelefono(const string &value);

    string getEmail() const;
    void setEmail(const string &value);

    string getNacimiento() const;
    void setNacimiento(const string &value);

private:
    string nombre;
    string apellido1;
    string telefono;
    string email;
    string nacimiento;
};


string Contacto::getNombre() const
{
return nombre;
}

void Contacto::setNombre(const string &value)
{
    if(value.size()==0)
        throw std ::string{"No has introducido ningun nombre"};
    nombre = value;
}

string Contacto::getApellido1() const
{
return apellido1;
}

void Contacto::setApellido1(const string &value)
{
    if(value.size()==0)
        throw std ::string{"No has introducido ningun apellido valido"};
    apellido1 = value;
}

string Contacto::getTelefono() const
{
return telefono;
}

void Contacto::setTelefono(const string &value){
    if(value.size() < 9)
        throw std ::string{"Los telefonos tienen 9 digitos"};
    telefono = value;
}

string Contacto::getEmail() const
{
return email;
}

void Contacto::setEmail(const string &value)
{
    if(value.size()==0)
        throw std ::string{"No has introducido ningún email valido"};
    email = value;
}

string Contacto::getNacimiento() const
{
return nacimiento;
}

void Contacto::setNacimiento(const string &value)
{
    if(value.size()==0)
        throw std ::string{"No has introducido ningún email valido"};
    nacimiento = value;
}



class Agenda{
public:
    void insertar(std::shared_ptr<Contacto>&c1);
    void borrar(const string& nomb_,const string & apell);
    void setAgenda(std::vector<std::shared_ptr<Contacto>> &agend);
    std::shared_ptr<Contacto> findNom(std::string nomb_,std::string apell);
    std::shared_ptr<Contacto> findAge(std::string nacimiento);
    std::shared_ptr<Contacto> print(std::string fechas);
    std::vector<std::shared_ptr<Contacto>> getAgenda();
private:
    std::vector<shared_ptr<Contacto>> agenda;

};

void Agenda::insertar(std::shared_ptr<Contacto> & c1)
{
    agenda.push_back(c1);
}

void Agenda::borrar(const string & nomb_,const string & apell)
{
    for(int i{0}; i<agenda.size(); i++){
        if(agenda.at(i)->getNombre() == nomb_ and agenda.at(i)->getApellido1() == apell){
            agenda.erase(agenda.begin()+i);
        }
    }
}



std::shared_ptr<Contacto> Agenda::findNom(string nomb_, string apell)
{
    for(int i{0}; i < agenda.size(); i++){
       if(agenda.at(i)->getNombre() == nomb_ and agenda.at(i)->getApellido1() == apell){
           std::cout<<"Contacto Encontrado"<<endl;
           return agenda.at(i);
       }
       else{
          cout<<"Dicho contacto no se encuentra en la agenda";
       }

   }
   if(agenda.size()==0){
       cout<<"Agenda vacia";
   }
}

std::shared_ptr<Contacto> Agenda::findAge(string nacimiento)
{
    for(int i{0}; i < agenda.size(); i++){
        if(agenda.at(i)->getNacimiento() == nacimiento){
            std::cout<<"Contacto Encontrado:"<<endl;
            return agenda.at(i);
        }
        else{
           cout<<"Dicho contacto no se encuentra en la agenda";
        }

    }
    if(agenda.size()==0){
        cout<<"Agenda Vacia";
    }


}

std::shared_ptr<Contacto> Agenda::print(std::string fechas)
{
    for(auto elem:agenda){
        if(elem->getNacimiento() == fechas){
            return elem;
        }
    }
}

std::vector<std::shared_ptr<Contacto>> Agenda::getAgenda()
{
    return agenda;
}

void Agenda::setAgenda(std::vector<std::shared_ptr<Contacto>> &agend)
{
 agenda = agend;
}
std::ostream &operator <<(std::ostream &os, Contacto &c){
    os<<"Nombre:"<<c.getNombre()<<endl;
    os<<"Apellido:"<<c.getApellido1()<<endl;
    os<<"Telefono:"<<c.getTelefono()<<endl;
    os<<"Email:"<<c.getEmail()<<endl;
    os<<"Fecha de nacimiento:"<<c.getNacimiento()<<endl;
    return os;
}

std::ostream &operator <<(std::ostream &os, Agenda &ag){

    if(ag.getAgenda().size()==0){
        os<<"Agenda Vacia";
    }

    for(auto elem:ag.getAgenda()){
        os<<elem;
        os<<"\n";
    }

    return os;
}

int main()
{

    bool condicion = true;
    int accion;
    string opc;
    Agenda agenda;
    string nombre{""};
    string apellido{""};
    string telefono = "";
    string email = "";
    string fecha = "";


    while (condicion == true) {
        cout<<"1.\tAdd Contacto\n"<<"2.\tEliminar Contacto\n"<<"3.\tBuscar Contacto por Nombre y Apellido\n"<<"4.\tBuscar Contacto por Fecha\n"<<"5.\tListar Agenda\n"<<"6.\tListar Birthdays\n"<<"7.\tAcabar Programa\n"<<"Elige una accion:";
        cin>>accion;
        while(accion < 1 || accion > 7){
            cout<<"Accion no valida por favor elija una correcta: ";
            cin>>accion;
        }
        cout<<endl;
        switch (accion) {
            case 1:
                std::cout<<"Introduzca el Nombre del contacto to add:";
                cin>>nombre;
                std::cout<<"Introduzca el Apellido del contacto to add:";
                cin>>apellido;
                std::cout<<"Introduzca el Telefono del contacto to add:";
                cin>>telefono;
                std::cout<<"Introduzca el Email del contacto to add:";
                cin>>email;
                std::cout<<"Introduzca la Fecha de nacimiento del contacto to add en formato dd/mm/aaaa:";
                cin>>fecha;
                try {
                    auto contacto = std::make_shared<Contacto>(nombre,apellido,telefono,email,fecha);
                    agenda.insertar(contacto);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;

            case 2:
            std::cout<<"Introduzca el Nombre del contacto to add:";
            cin>>nombre;
            std::cout<<"Introduzca el Apellido del contacto to add:";
            cin>>apellido;
                agenda.borrar(nombre,apellido);
                break;
            case 3:
                std::cout<<"Introduzca el Nombre del contacto a buscar:";
                cin>>nombre;
                std::cout<<"Introduzca el Apellido del contacto a buscar:";
                cin>>apellido;
                cout<<*agenda.findNom(nombre,apellido);
                break;
            case 4:
                std::cout<<"Introduzca la fecha del contacto a buscar en formato dd/mm/aaaa:";
                cin>>fecha;
                cout<<*agenda.findAge(fecha);
                break;
            case 5:
                cout<<agenda;
            case 6:
                std::cout<<"Introduzca la fecha del contacto a buscar en formato dd/mm/aaaa:";
                cin>>fecha;
                cout<<*agenda.print(fecha);
            case 7:
                condicion = false;
                break;
            }
    }

    return 0;
}

