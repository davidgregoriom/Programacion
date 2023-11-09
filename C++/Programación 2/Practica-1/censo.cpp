#include "censo.h"
#include <iostream>

using namespace std;
Censo::Censo(string _name,string _DNI,string _phone, int _year){
    setName(_name);
    setAge(_year);
    setDNI(_DNI);
    setPhone(_phone);
}

void Censo::print(){
    cout << name << "\n";
    cout << year << "\n";
    cout << DNI << "\n";
    cout << phone << "\n";
}

string Censo::getPhone() const
{
    return phone;
}

void Censo::setPhone(const string &value)
{
    phone = value;
}

string Censo::getDNI() const
{
    return DNI;
}

void Censo::setDNI(const string &value)
{
    DNI = value;
}

int Censo::getYear() const
{
    return year;
}

void Censo::setYear(int value)
{
    year = value;
}

string Censo::getName() const
{
    return name;
}

void Censo::setName(const string &value)
{
    name = value;
}

int Censo::getAge() const
{
    return age;
}

void Censo::setAge(int value)
{
    age = (value- year);
}

int Censo::getIsAdult() const
{
    return isAdult;
}

void Censo::setIsAdult(int value)
{
    if(isAdult < 18) isAdult = 0;
    else isAdult = value;
}


