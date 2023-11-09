#include <iostream>
#include <array>

using namespace std;

int main()
{
    string cad("");
    cout<<"Introduce un texto:\n";
    int contador {0};
    getline(std::cin,cad);
    for(char elem:cad){
        if(elem =='a'||elem =='A'){
            contador++;
        }
    }

    cout<<"hay " << contador << " numero de a   ";
}
