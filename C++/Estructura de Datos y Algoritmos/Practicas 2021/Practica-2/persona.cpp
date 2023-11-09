#include "persona.h"


Persona::Persona(const std::string &name, const std::string &dni, int gender):name{name}, dni{dni}, gender{gender}
{

}

const std::string &Persona::get_name() const
{
    return name;
}

int Persona::get_gender() const
{
    return gender;
}

const std::string &Persona::get_dni() const
{
    return dni;
}

bool Persona::operator==(const Persona &other) const
{
    if(other.get_dni() == dni && other.get_gender() == gender && other.get_name() == name){
        return true;
    }
    return false;
}
