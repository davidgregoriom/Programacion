#include "person.h"
person::person(string _name, int _age, string _num)
{
    name=_name;
    age=_age;
    num=_num;
}

string person::getName() const
{
return name;
}

void person::setName(const string &value)
{
name = value;
}

int person::getAge() const
{
return age;
}

void person::setAge(int value)
{
    if(age<0)throw string{"Edad incorrecta"};
    age = value;
}

string person::getNum() const
{
return num;
}

void person::setNum(const string &value)
{
    if(value.length()!=9)throw string{"Marque el numero de nuevo XD"};
    num = value;
}



ostream &operator <<(ostream &os, const person &p)
{
    os << "Nombre: " << p.getName() << "\n";
    os << "Edad: " << p.getAge() << "\n";
    os << "Número: " << p.getNum() << "\n";
    return os;
}
