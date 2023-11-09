#include "cola.h"
#include "gente.h"

using namespace std;

int cola::getMax() const{
    return max;
}

void cola::setMax(int value){
    max = value;
}

int cola::getCont() const{
    return cont;
}

void cola::setCont(int value){
    cont = value;
}

int cola::getGent() const{
    return gent;
}

void cola::setGent(int value){
    gent = value;
}

cola::cola(int value){
    max = value;
}

void cola::push_back(int a, string b){
    if(getMax() - getGent() == 0){
        throw string{"La cola esta llena"};
    }
    gente gen1;
    gen1.setNum(a);
    gen1.setNom(b);
    vec.push_back(gen1);

    int j = getGent() + 1;
    setGent(j);
}

void cola::print(){
    for(int i = getCont(); i <= getMax(); i++){
        cout << vec.at(i).getNom() << endl;
    }
}

void cola::peekt(){
    int x = getCont();
    x = x + 1;
    if(x > getMax()){
        throw string{"Ya no quedan mas gente en la cola"};
    }
    cout << vec.at(x).getNum() << " " << vec.at(x).getNom() << endl;
}

void cola::pop_front(){
    if(getMax()<getCont()){
        throw string{"Ya no queda nadie por atender"};
    }
    cout << vec.at(getCont()).getNum() << " " << vec.at(getCont()).getNom() << endl;

    int a = getCont() + 1;
    setCont(a);

    int h = getGent() - 1;
    setGent(h);
}

int cola::getSize(){
    int r{0};
    r = getMax() - getCont();

    return r;
}

bool cola::isEmpty(){
    if(getMax() < getCont()){
        return true;
    }
    else{
        return false;
    }
}

