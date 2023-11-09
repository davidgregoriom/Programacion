#ifndef PERSON_H
#define PERSON_H
#include <array>
#include <iostream>

using namespace std;


class person{
public:

    person(string _name,int _age, string _num);
    string getName() const;
    void setName(const string &value);

    int getAge() const;
    void setAge(int value);
    string getNum() const;
    void setNum(const string &value);

private:
    string name,num;
    int age;



};
ostream &operator <<(ostream & os,person const & p);


#endif // PERSON_H
