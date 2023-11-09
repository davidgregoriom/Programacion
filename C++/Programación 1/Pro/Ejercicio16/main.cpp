#include <iostream>

using namespace std;

int main()
{
   int numero {0};
   cout<< "Introduce un numero:";
   cin>> numero;


   int suma{0};
   int i{0};

   while(i <= numero){
       suma += i;
       i++;
   }
   cout <<"El sumatorio da "<< suma <<"\n";
}
