#ifndef LISTIN_H
#define LISTIN_H
#include <vector>
#include <iostream>
#include "person.h"
#include <functional>

using namespace std;

class listin
{
public:
    listin();
    ~listin();
    void addPerson(person* p);
    void forEach (function<void(person*)>op)const;
    person *find(function<bool(person*)>op)const;
    listin filter(function<bool(person*)>op)const;

private:
    vector<person*> listin;
};

#endif // LISTIN_H
