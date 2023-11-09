#ifndef GENTE_H
#define GENTE_H
#include <iostream>

using namespace std;

class gente{
    private:
        int num;
        string nom;

    public:
        gente();
        int getNum() const;
        void setNum(int value);
        string getNom() const;
        void setNom(const string &value);
};

#endif // GENTE_H
