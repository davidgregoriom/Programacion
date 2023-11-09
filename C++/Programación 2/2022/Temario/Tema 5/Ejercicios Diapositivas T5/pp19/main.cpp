#include <iostream>
#include <string>
#include "Templates.h"

using namespace std;

std::ostream & operator <<(std::ostream & os, std::vector<std::vector<double>> const & p){
  for(auto i:p)
  {
      for(auto j:i)
        {
            os << j <<" ";
        }
       os << endl;
  }

  return os;
}

int main()
{
    cout << "Prueba de plantillas..." << endl;
    int a=8,b=2,res=0;
    double f1=8.2,f2=2.2,resD=0.0;

    std::string c1="Hola me llamo";
    std::string c2="Pepe",resS;

    std::vector<std::vector<double>> A{{1,0,0},{0,1,0},{0,0,1}};
    std::vector<std::vector<double>> B{{1,1,1},{1,1,1},{1,1,1}},resM,resSumaM,resRestaM;

    res=sumar<int>(a,b);
    resD=sumar<double>(f1,f2);
    resS=sumar<std::string>(c1,c2);

    std::cout<<"El resultado de sumar 2 enteros es: "<< res <<std::endl;
    std::cout<<"El resultado de sumar 2 cadenas es: "<< resD <<std::endl;
    std::cout<<"El resultado de sumar 2 cadenas es: "<<resS<<std::endl;

    resM=multiplicar<>(A,B);
    resSumaM=sumar<>(A,B);
    resRestaM=restar<>(A,B);

    std::cout<<"El resultado de sumar 2 matrices es : "<<std::endl;
    std::cout<<resSumaM<<std::endl;

    std::cout<<"El resultado de restar 2 matrices es : "<<std::endl;
    std::cout<<resRestaM<<std::endl;

    std::cout<<"El resultado de multiplicar 2 matrices es : "<<std::endl;
    std::cout<<resM<<std::endl;

    cout << "Terminando..." << endl;
    return 0;
}
