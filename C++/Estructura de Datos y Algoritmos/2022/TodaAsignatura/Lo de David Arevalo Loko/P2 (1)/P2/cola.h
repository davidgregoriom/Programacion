#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <vector>
#include "gente.h"

using namespace std;

class cola{
    private:
        vector<gente> vec;
        int max{0};
        int cont{0};
        int gent{0};

    public:
        cola(int m);
        void push_back(int a, string b);
        void print();
        void peekt();
        void pop_front();
        int getSize();
        bool isEmpty();

        int getMax() const;
        void setMax(int value);
        int getCont() const;
        void setCont(int value);
        int getGent() const;
        void setGent(int value);
};

#endif // LLAMADAS_H
