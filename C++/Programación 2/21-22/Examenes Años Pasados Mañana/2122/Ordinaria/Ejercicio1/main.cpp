#include <iostream>

using namespace std;

int mayor(const int & numero ){
    if(numero<=0)throw string ("tiene que ser positivo");
    for(int i=numero-1;i>=0;i--){
        if(i%3==0){
            return i;
        }
    }


}

int main()
{
   int numero;
   cout<< "Dame numero:"<<endl;
   cin >>numero;
   cout<<"El mayor número múltiplo de 3 de ese numero es: " <<mayor(numero);
}
