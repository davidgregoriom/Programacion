#include "bolsa.h"



Bolsa::Bolsa()
{
    for(int i=1;i<21;i++){
         bolas.push_back(i);
    }
}

bool Bolsa::empty_quedanBolas() const
{
    if(bolas.size()==0){
        return true;
    }else{
        return false;
    }
}

int Bolsa::pop_sacarBola(int sorteo)
{
    for(auto elem:bolas){
        if(elem==sorteo){
            bolas.erase(bolas.begin()+sorteo);
        }
    }
}


vector<int> Bolsa::getBolas() const
{
    return bolas;
}

void Bolsa::setBolas(vector<int> &value) const {
         value = bolas;
}
