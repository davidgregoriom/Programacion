#include <iostream>
#include <memory>

using namespace std;

class Base{
public:
   virtual void Saludar(){cout<<"soy Base";}
};

class Der1:public Base
{
public:
    void Saludar(){cout<<"Soy Derivada 1"<< endl;}
};


int main(){
    Base *miBase,*miDer1;

    miBase= new Base;
    miDer1= new Der1;

    miBase->Saludar();
    miDer1->Saludar();


    return 0;
}
