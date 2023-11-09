#include "person.h"

Person::Person()
{

}

string Person::getName() const
{
    return name;
}

void Person::setName(const string &value)
{
    name = value;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int value)
{
    if (age< 0) cout << "Edad incorrecta" << "\n";
    age = value;
}

string Person::getPhone() const
{
    return phone;
}

void Person::setPhone(const string &value)
{
    phone = value;
}
