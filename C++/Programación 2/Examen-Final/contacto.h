#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>
#include <array>
#include <set>
#include <vector>
#include <memory>
#include <istream>

using namespace std;


class Contacto
{
public:
    Contacto();
    Contacto(string Nombre,string Apellido,string Telefono,string correo,string fdnacimiento);


    string Nombre() const;
    void setNombre(const string &Nombre);

    string Apellido() const;
    void setApellido(const string &Apellido);

    string Telefono() const;
    void setTelefono(const string &Telefono);

    string correo() const;
    void setCorreo(const string &correo);

    string fdnacimiento() const;
    void setFdnacimiento(const string &fdnacimiento);
    friend std::ostream& operator<<(ostream &os, const Contacto empleado);
private:
    string Nombre_;
    string Apellido_;
    string Telefono_;
    string correo_;
    string fdnacimiento_;

};
class ElementListaSimple {
    public:
        Contacto dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        // Constructor
        ElementListaSimple(const Contacto& dato_) : dato{dato_} {}
};
class Agenda
{
public:
        Agenda();
        Agenda(const Contacto&);

        void insert(std::shared_ptr<ElementListaSimple>& lista,const Contacto& dato);
        void erase(std::shared_ptr<ElementListaSimple>& lista,const Contacto &dato);
        int find1(std::shared_ptr<ElementListaSimple>& lista,const Contacto& dato) const;
        int find2(std::shared_ptr<ElementListaSimple>& lista,const Contacto& dato) const;
        friend std::ostream& operator<<(std::ostream& os, const Agenda& empleado);
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
        std::shared_ptr<ElementListaSimple> back = nullptr;

};
std::ostream& operator<<(std::ostream& os, const Contacto& empleado);
std::ostream& operator<<(std::ostream& os, const Agenda& empleado);



#endif // CONTACTO_H
