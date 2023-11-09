#include <iostream>

using namespace std;

int mcm(int divisor,int x, int y){
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


int main()
{
    int x,y;
    int resultado;
    cout << "Valor 1:";
    cin >> x;
    cout << "Valor 2:";
    cin >> y;
    resultado=mcm(2,x,y);
    cout << "El mínimo común múltiplo es:  "<< resultado << endl;
    return 0;
}
