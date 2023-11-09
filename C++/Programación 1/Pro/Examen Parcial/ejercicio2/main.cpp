#include <iostream>
#include <array>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{

    int suma {0};
    int mostrado{0};
    int num{1};
    bool primo{true};
    vector<int>apartado2{};

    //Aparato 1;
    for(int i= 1; i<=100;i++)suma=suma + i;
    cout << suma<< "\n\n";
    //Apartado 2;
    while(mostrado < 10){
        if(num % 6==0){
            cout<< num<< "\n";
            mostrado++;
        }
        num++;
    }

    //Apartado 3;

    int primoseguro;
    mostrado =0;
    num = 50;

    while(mostrado <1){
        for(int i=0;i=num/2; i++){
            if(num%i==0){
                primo=false;
                break;
            }else if(primo==true){
                mostrado =1;
                primoseguro=num;


            }else{
                num++;
            }


        }


    }
    cout << primoseguro;



    return 0;
}
