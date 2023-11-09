#ifndef CENSO_H
#define CENSO_H
#include <iostream>
 #include <string>

using namespace std;

class Censo
{
public:
    Censo(string _name,string _DNI,string _phone, int _year);
    void print();

    string getPhone() const;
    void setPhone(const string &value);

    string getDNI() const;
    void setDNI(const string &value);

    int getYear() const;
    void setYear(int value);

    string getName() const;
    void setName(const string &value);

    int getAge() const;
    void setAge(int value);

    int getIsAdult() const;
    void setIsAdult(int value);

private:
    string name;
    int year;
    string DNI;
    string phone;
    int age;
    int isAdult;
};

#endif // CENSO_H
