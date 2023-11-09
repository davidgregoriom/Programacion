#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person();
    string getName() const;
    void setName(const string &value);

    int getAge() const;
    void setAge(int value);

    string getPhone() const;
    void setPhone(const string &value);

private:
    string name;
    int age;
    string phone;
};

#endif // PERSON_H
