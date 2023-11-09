#include <iostream>
#include <array>


using namespace std;

int main()
{
    string texto{""};
    cout<<"Introduce un texto\n";
    getline(cin,texto);
    string textomod{""};
    array<int,3>numbers{1,2,3};
    for(auto elem: texto){
        if(elem !='1'&& elem !='2' && elem !='3'){
            texto.find(elem++);
            textomod.push_back(elem);
        }
    }

    cout<<textomod<<"\n";

}
