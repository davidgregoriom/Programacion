#include <iostream>
#include <vector>
#include <memory>
#include <functional>

using namespace std;
template<typename T>
class Data
{
private:
    std::string clave;
    T valor;
public:
    Data(std::string const& _clave, T const & _valor);
    std::string getClave() const;
    void setClave(const std::string &value);
    T getValor() const;
    void setValor(const T &value);
};





template<typename T>
Data<T>::Data(const std::string & _clave, const T &_valor)
{
    clave = _clave;
    valor = _valor;
}

template<typename T>
std::string Data<T>::getClave() const
{
    return clave;
}

template<typename T>
void Data<T>::setClave(const std::string &value)
{
    clave = value;
}

template<typename T>
T Data<T>::getValor() const
{
    return valor;
}

template<typename T>
void Data<T>::setValor(const T &value)
{
    valor = value;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Data<T> const & d){
    os<<d.getClave()<<":\n"<<d.getValor()<<"\n";
    return os;
}

template<typename T>
class Listado
{
private:
    std::vector<std::shared_ptr<Data<T>>>datos;
public:
    Listado();
    void inserta(std::shared_ptr<Data<T> > a);
    void elimina(std::string const& clave);
    std::shared_ptr<Data<T> > find(const std::function<bool(std::shared_ptr<Data<T> >)> &op)const;
    std::vector<std::shared_ptr<Data<T> > > getDatos() const;
};


template<typename T>
Listado<T>::Listado()
{

}

template<typename T>
void Listado<T>::inserta(std::shared_ptr<Data<T> > a)
{
    for(auto const & n: datos){
        if(n->getClave() == a->getClave()) throw  std::string{"Ya existe una persona con ese identificador"};
    }
    datos.push_back(a);
}

template<typename T>
void Listado<T>::elimina(const std::string &clave)
{
    for(unsigned int long i{0}; i < datos.size(); i++){
        if(datos.at(i)->getClave() == clave){
            datos.erase(datos.begin()+i);
            return;
        }
    }

    throw std::string{"No existe la persona que quieres borrar"};
}

template<typename T>
std::shared_ptr<Data<T> > Listado<T>::find(std::function<bool (std::shared_ptr<Data<T> >)> const & op) const
{
    for(auto n:datos){
        if(op(n))return n;
    }
    return nullptr;
}

template<typename T>
std::vector<std::shared_ptr<Data<T> > > Listado<T>::getDatos() const
{
    return datos;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Listado<T> const & l){
    for(auto n: l.getDatos()){
        os<<*n<<"\n";
    }
    os<<"\n";
    return os;
}

template<typename T>
Listado<T> operator+(Listado<T> const& s, Listado<T> const & l){
    Listado<T> result = s;
    for(auto n: l.getDatos()){
        result.inserta(n);
    }
    return result;
}

class Persona
{
private:
    std::string nombre;
    int nacimiento;
    std::string telefono;
public:
    Persona();
    Persona(std::string const & _nombre, int _nacimiento, std::string const & _telefono);
    std::string getNombre() const;
    void setNombre(const std::string &value);
    int getNacimiento() const;
    void setNacimiento(int value);
    std::string getTelefono() const;
    void setTelefono(std::string value);
};

std::ostream & operator<<(std::ostream & os, Persona const & p);

std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    if(value.size()==0)throw std::string{"Nombre no puede ir en blanco"};
    nombre = value;
}

int Persona::getNacimiento() const
{
    return nacimiento;
}

void Persona::setNacimiento(int value)
{
    nacimiento = value;
}

std::string Persona::getTelefono() const
{
    return telefono;
}

void Persona::setTelefono(std::string value)
{
    if(value.size()!=9)throw std::string{"Los telefonos tienen 9 digitos"};
    telefono = value;
}

Persona::Persona()
{

}

Persona::Persona(const std::string &_nombre, int _nacimiento, const std::string &_telefono)
{
    setNombre(_nombre);
    setTelefono(_telefono);
    setNacimiento(_nacimiento);
}

std::ostream &operator<<(std::ostream &os, const Persona &p)
{
    os<<"Nombre{"<<p.getNombre()<<"}\nNacimiento{"<<p.getNacimiento()<<"}\nTelefono{"<<p.getTelefono()<<"}\n";
    return os;
}


int main()
{
    Listado<Persona> listaPersonas;
    bool condicion = true;
    int accion, nacimiento;
    string clave;
    string nombre;
    string telefono;

    while(condicion == true){
        cout<<"1.\tAñadir Persona\n"<<"2.\tEliminar Persona\n"<<"3.\tBuscar Persona\n"<<"4.\tListar\n"<<"5.\tAcabar Programa\n"<<"Elige una accion:";
        cin>>accion;
        while(accion < 1 || accion > 5){
            cout<<"Accion no valida por favor elija una correcta: ";
            cin>>accion;
        }

        cout<<endl;
        switch (accion) {
            case 1:
                cout<<"Introduce la clave para la persona:";cin>>clave;
                cout<<"Introduce el nombre de la persona:";cin>>nombre;
                cout<<"Introduce el año de nacimiento de la persona:";cin>>nacimiento;
                cout<<"Introduce el telefono de la persona:";cin>>telefono;
                cout<<endl;
                try {
                    auto a = std::make_shared<Data<Persona>>(Data<Persona>(clave,Persona{nombre,nacimiento,telefono}));
                    listaPersonas.inserta(a);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 2:
                try {
                    cout<<"Introduce la clave de la persona a borrar:";cin>>clave;
                    cout<<endl;
                    listaPersonas.elimina(clave);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 3:
                try {
                    cout<<"Introduce la clave de la persona que deseas buscar:";cin>>clave;
                    auto encontrada = listaPersonas.find([=](std::shared_ptr<Data<Persona> > a){
                        return a->getClave() == clave;
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else std::cout << "Persona no encontrada\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 4:
                cout<<listaPersonas;
                break;
            case 5:
                condicion = false;
                break;
        }
    }
    return 0;
}
