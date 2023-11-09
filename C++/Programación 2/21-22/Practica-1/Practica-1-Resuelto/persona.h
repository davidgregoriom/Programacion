#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>

using namespace std;

class persona
{
private:
    int birthday;
    string name;
    string dni;
    string phone;



public:
    persona();

    int getBirthday() const;
    void setBirthday(int value);
    string getName() const;
    void setName(const string &value);
    string getDni() const;
    void setDni(const string &value);
    string getPhone() const;
    void setPhone(const string &value);
    void print() const;
    int age(int a)const;
    bool isAdult (int a)const;
};

#endif // PERSONA_H
