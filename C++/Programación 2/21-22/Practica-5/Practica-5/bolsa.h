#ifndef BOLSA_H
#define BOLSA_H
#include <iostream>
#include <memory>
#include <vector>
#include "jugador.h"

using namespace std;



class Bolsa
{

public:
    Bolsa();
    int size(shared_ptr<vector<int>>punterodebolas) const;
    bool empty_quedanBolas() const;
    int pop_sacarBola(int sorteo) ;
    vector<int> getBolas() const;
    void setBolas(vector<int> &value) const;

protected:
    vector<int>bolas;

};


#endif // BOLSA_H
