#include <iostream>
#include<string>
#include <array>
using namespace std;

int main(){
    array<int,7> notas={2,3,4,5,6,7,8};
    int pos= -1;
    bool encontrado= false;

    for(int num: notas){
        pos = pos+1;

        if(num==7){
            encontrado= true;
            cout<<"El array tiene el "<< num <<"\n";
            cout<<"Esta en la posicion" << pos <<"\n";
            break;
        }
    }
    if (!encontrado) {
       std::cout << "El array no tiene 7\n";
    }
}
