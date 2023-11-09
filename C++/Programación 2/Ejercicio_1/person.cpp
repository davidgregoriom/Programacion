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

string Person::getPhone() const
{
    return phone;
}

void Person::setPhone(const string &value)
{
    phone = value;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int value)
{
    age = value;
}

void Person::print()
{
   cout <<  name << "\n";
   cout <<  age << "\n";
   cout << phone << "\n";
}
