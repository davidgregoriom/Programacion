#include <iostream>

using namespace std;

#include <memory>

struct Nodo {
    int info;
    std::shared_ptr<Nodo> izq = nullptr;
    std::shared_ptr<Nodo> der = nullptr;
};

class ABB {
private:
    std::shared_ptr<Nodo> root = nullptr;

public:
    ABB() { root=nullptr; }
    bool esDegenerado() const;

};
bool esDegenerado_(std::shared_ptr<Nodo> r){
    if(r->der != nullptr){
        if(r->izq != nullptr)return false;
        else{return esDegenerado_(r->der);}
    }else if(r->izq != nullptr){
        if(r->der != nullptr)return false;
        else{return esDegenerado_(r->izq);}
    }else{
        return true;
    }
}
bool ABB::esDegenerado() const
{
    return esDegenerado_(root);
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

