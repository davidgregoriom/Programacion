#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int numero_adivinar=rand()%50 +1;
    int numerocree;
    for(int i{1};i<6;i++){
        cout<<"Dime el numeroq que crees,piensa que es del 1 al 50 , no te pases\n";
        cin>>numerocree;
        if(numerocree<numero_adivinar){
            cout<<"Es mayor que el que has dicho\n";
            cout<<"Te queda "<<5-i<<" intentos\n";

        }else if(numerocree>numero_adivinar){
            cout<<"Es menor que el que has dicho\n";
            cout<<"Te queda "<<5-i<<" intentos\n";
        }else{
            cout<<"¡Lo has adivinado!\n";
            i+=5;
        }

    }
    cout <<"El numero era: "<<numero_adivinar<<"\n";

    return 0;
}
