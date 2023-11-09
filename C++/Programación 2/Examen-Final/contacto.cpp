#include "contacto.h"



Contacto::Contacto(string Nombre, string Apellido, string Telefono, string correo, string fdnacimiento)
{
    Nombre=Nombre_;
    Apellido=Apellido_;
    Telefono=Telefono_;
    correo=correo_;
    fdnacimiento=fdnacimiento_;
}

string Contacto::Nombre() const
{
    return Nombre_;
}

void Contacto::setNombre(const string &Nombre)
{
    if(Nombre.size()==0)
        throw string{"No has introducido el nombre"};
    Nombre_ = Nombre;
}

string Contacto::Apellido() const
{
    return Apellido_;
}

void Contacto::setApellido(const string &Apellido)
{
    if(Apellido.size()==0)
            throw string{"No has introducido el apellido"};
    Apellido_ = Apellido;
}

string Contacto::Telefono() const
{
    return Telefono_;
}

void Contacto::setTelefono(const string &Telefono)
{
    if(Telefono.size()==0)
        throw string{"No has introducido el telefono"};
    Telefono_ = Telefono;
}

string Contacto::correo() const
{
    return correo_;
}

void Contacto::setCorreo(const string &correo)
{
    if(correo.size()==0)
        throw string{"No has introducido el correo"};
    correo_ = correo;
}

string Contacto::fdnacimiento() const
{
    return fdnacimiento_;
}

void Contacto::setFdnacimiento(const string &fdnacimiento)
{
    if(fdnacimiento.size()==0)
        throw string{};
    fdnacimiento_ = fdnacimiento;
}

void Agenda::insert(std::shared_ptr<ElementListaSimple>& lista,const Contacto &dato)
{
    std::shared_ptr<ElementListaSimple> elem = std::make_shared<ElementListaSimple>(ElementListaSimple{dato});
        elem->next = lista;
            lista = elem;


}
void Agenda::erase(std::shared_ptr<ElementListaSimple>& lista,const Contacto &dato)
{
    std::shared_ptr<ElementListaSimple> elem = std::make_shared<ElementListaSimple>(ElementListaSimple{dato});
        elem->next = lista;
        lista = elem;
}

std::ostream& operator<<(ostream &os, const Contacto empleado)
{
    os <<empleado.Nombre_<<empleado.Apellido_<<empleado.correo_<<empleado.fdnacimiento_<<empleado.Telefono_;
    return os;
}
/*std::ostream& operator<<(std::ostream& os, const Agenda& empleado){
    os <<empleado.Contact();
    return os;
}


int Agenda::find1(std::shared_ptr<ElementListaSimple>& lista,const Contacto &dato) const
{
    std::shared_ptr<ElementListaSimple>iterator = lista;
        int found = -1;
        int idx = 0;
        while (iterator != nullptr) {
            if (equal(iterator->dato, dato)) {
                found = idx;
                break;
            }
            iterator = iterator->next;
            idx++;
        }
        return found;
}

int Agenda::find2(std::shared_ptr<ElementListaSimple>& lista,const Contacto &dato) const
{
    std::shared_ptr<ElementListaSimple> iterator = lista;
        int found = -1; // If not found, it will return -1
        int idx = 0;
        while (iterator != nullptr) {
            if (equal(iterator->dato, dato)) {  // Use external function to compare
                found = idx;
                break;
            }
            iterator = iterator->next;
            idx++;
        }
        return found;
}
*/

