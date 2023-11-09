#include <iostream>

using namespace std;

int mcd(int x, int y){

    int divisor;
    while(y!=0){
       divisor=y;
       y=x%y;
       x=divisor;
    }
    return x;
}



int main()
{
    int x,y;
    int resultado;
    cout << "Valor 1:";
    cin >> x;
    cout << "Valor 2:";
    cin >> y;
    resultado=mcd(x,y);
    cout << "El máximo común divisor es:  "<< resultado << endl;
    return 0;
}
