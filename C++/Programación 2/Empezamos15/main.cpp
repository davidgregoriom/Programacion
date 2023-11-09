#include <iostream>
#include <vector>
#include <memory>


using namespace std;

class Contacto{
public:
    string getNombre() const;
    void setNombre(const string &value);

    string getApellido() const;
    void setApellido(const string &value);

    string getTelefono() const;
    void setTelefono(const string &value);

    string getEmail() const;
    void setEmail(const string &value);

    string getNacimiento() const;
    void setNacimiento(const string &value);

private:
    string nombre,apellido,telefono,email,nacimiento;
};






string Contacto::getNombre() const
{
    return nombre;
}

void Contacto::setNombre(const string &value)
{
    if(value.size()==0){
        throw string{"No has introducido bien el nombre"};}
    else{
        nombre = value;
    }

}

string Contacto::getApellido() const
{
return apellido;
}

void Contacto::setApellido(const string &value)
{
    if(value.size()==0){
        throw string{"No has introducido bien el apellido"};}
    else{
        apellido = value;
    }
}

string Contacto::getTelefono() const
{
return telefono;
}

void Contacto::setTelefono(const string &value)
{
    if(value.size()!=9){
        throw string{"No has introducido bien el telefono"};}
    else{
        nombre = value;
    }
}

string Contacto::getEmail() const
{
return email;
}

void Contacto::setEmail(const string &value)
{
    if(value.size()==0){
        throw string{"No has introducido bien el email"};}
    else{
        nombre = value;
    }
}

string Contacto::getNacimiento() const
{
return nacimiento;
}

void Contacto::setNacimiento(const string &value)
{
    if(value.size()==0){
        throw string{"No has introducido bien la fecha de nacimiento"};}
    else{
        nombre = value;
    }
}
class Agenda{
public:
    void insertar(shared_ptr<Contacto>c1);
    void borrar(string name_);
    shared_ptr<Contacto>encontrarnombre();
    shared_ptr<Contacto>encontrarnacimiento();
    shared_ptr<Contacto>print();

    vector<shared_ptr<Contacto> > getAgenda() const;
    void setAgenda(const vector<shared_ptr<Contacto> > &value);

private:
    vector<shared_ptr<Contacto>>agenda;
};

int main(){




}




void Agenda::insertar(shared_ptr<Contacto> c1)
{
   agenda.push_back(c1);
}

vector<shared_ptr<Contacto> > Agenda::getAgenda() const
{
return agenda;
}

void Agenda::setAgenda(const vector<shared_ptr<Contacto> > &value)
{
agenda = value;
}
