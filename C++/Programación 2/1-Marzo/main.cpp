#include <iostream>
#include "complejo.h"
#include <memory>
using namespace std;

//Complejo sumar(Complejo a, Complejo b){
    //Complejo result;
    //result.setA((a.getA())+(b.getA()));
    //result.setB((a.getB())+(b.getB()));
    //return result;
//}
Complejo add(Complejo & num1,Complejo & num2){
    Complejo result;
    float real=num1.getReal()+num2.getReal();
    float im=num1.getImag()+num2.getImag();
    result.setReal(real);
    result.setImaginaria(im);
    return result;
}
int main()
{
    Complejo num;
    float real;
    float imaginaria;
    cout << "Introduce la parte real de un numero complejo: \n";
    cin>>real;
    num.setReal(real);
    cout << "Introduce la parte imaginaria de un numero complejo: \n";
    cin>>imaginaria;
    num.setImaginaria(imaginaria);
    cout<<"El numero complejo introducido es: \n";
    num.print();

}

    //Complejo comp;
    //shared_ptr<Complejo>p_compl;
    //p_compl = make_shared<Complejo>();
    //shared_ptr<Complejo> p_otro;
    //p_otro = p_compl;


    //float real;
    //float imaginaria;
    //Complejo uno = Complejo(1,2);
    //Complejo dos = Complejo(2,3);

    //std::cout << "Mete tu numero complejo: ";
    //std::cin >> real  >> imaginaria ;
    //Complejo tres = Complejo(real,imaginaria);

    //uno.print();
    //dos.print();
    //tres.print();
    //Complejo add = sumar (dos,tres);
    //std::cout << add.getA()  << ", " << add.getB() << "\n";
    //Complejo add2 = sumar (dos,uno);
    //std::cout << add2.getA()  << ", " << add2.getB() << "\n";



