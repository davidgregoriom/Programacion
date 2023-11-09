#include <iostream>
#include "integer.h"
#include <vector>

using namespace std;
/*
int operator*(int x, int y){
{
    int divisor =2;
    int auxiliar=1;

    while(x%divisor==0 || y%divisor==0){
        auxiliar*=divisor;
        if(x%divisor==0){
            x/=divisor;
        }if(y%divisor==0){
            y/=divisor;
        }
    }
    if(divisor<=x||divisor<=y){
        auxiliar*=mcm(divisor+1,x,y);
    }
    return auxiliar;

}

}

int operator/(int x, int y){
    int divisor;
    while(y!=0){
       divisor=y;
       y=x%y;
       x=divisor;
    }
    return x;
}
*/
int main()
{
   vector<integer> numeros;
  bool condicion= true;
int accion;
 int numero1;
 int numero2;
 while(condicion==true){
     cout << "1,2,3,4,5,6\n";
     cin >> accion;
     while(accion <1||accion>6){
     cout << "no valido\n";
     cin >> accion;
}
     cout << endl;
     switch(accion){
     case 1:
         cout << "introduce numero\n";
         cin >> numero1;

         try {


     }catch(string m){
             cout << m << endl;

         }
     case 2:

     case 3:

     case 4:

     case 5:

     case 6:
         condicion= false;
         break;
     }
 }
}

