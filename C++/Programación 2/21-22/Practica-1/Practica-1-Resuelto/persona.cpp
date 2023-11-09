#include "persona.h"

int persona::getBirthday() const
{
    return birthday;
}

void persona::setBirthday(int value)
{
    birthday = value;
}

string persona::getName() const
{
    return name;
}

void persona::setName(const string &value)
{
    name = value;
}

string persona::getDni() const
{
    return dni;
}
void persona::setDni(const string &value)
{
    dni = value;
}

string persona::getPhone() const
{
    return phone;
}

void persona::setPhone(const string &value)
{
    phone = value;
}

void persona::print() const
{
    cout << name;
    cout << phone;
    cout << birthday;
    cout << dni;
}

int persona::age(int a) const
{
    return (a-birthday);
}

bool persona::isAdult(int a) const
{
    return a;
}

persona::persona(){

}
